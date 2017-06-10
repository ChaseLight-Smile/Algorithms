package solution;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Map;
import java.util.Set;
import java.util.HashMap;
import java.util.Iterator;
/** hdu1003
 * 功能: 最大子数组问题的应用，包含两个知识点: IO流、寻找最大子数组
 * @author 朱君鹏
 *
 */
public class HDU1003 { //注意，在HDU中类名必须为Main，在提交时应该做出修改

	public static void main(String[] args){   //注意，HDU中必须有主函数，和LeetCode不同
		//键盘输入采用字节流
		InputStream in = System.in;
		//将字节流转换为字符流
		InputStreamReader input = new InputStreamReader(in);
		//使用缓冲字符流提高读取效率
		BufferedReader bufferedReader = new BufferedReader(input);
		
		String content = null;
		try{
			while((content = bufferedReader.readLine()) != null){
				Integer rowCount = Integer.parseInt(content);
				if(rowCount >= 1 && rowCount <= 20){
					Map<Integer,String> map = new HashMap<Integer,String>();
					//获取到输入
					int count = 1;     //说明已经正确的输入需要计算的行数，并且保存在rowContent变量中
					while(count <= rowCount && (content = bufferedReader.readLine()) != null){
						map.put(count,content);
						count++;
					}
					
					//从map中将输入取出，并将其放入到ArrayList中
					//现在已经将所有的需要计算的数据存放在Map中，接下来需要遍历Map，并且将其中的数据取出来
					Set<Map.Entry<Integer,String>> set = map.entrySet();
					Iterator it = set.iterator();
					while(it.hasNext()){
						Map.Entry<Integer,String> entry = (Map.Entry<Integer, String>) it.next();
						String output = entry.getValue(); //得到map中存放的值，这些值被存储为String类型，并且中间用空格分开
						String[] ops = output.split(" ");  //ops数组中存放的是操作数，并且操作数通常很大，不能直接转成int，直接将字符串保存到ArrayList中
				        int length = ops.length;
				        if(Integer.parseInt(ops[0]) != length-1){
				        	//说明后面输入的操作数的个数不正确，此时应该结束循环
				        	System.out.println("您输入的操作数个数不正确，请重新输入");
				        	break;
				        }else{
				        	//说明输入的操作数个数正确，此时进行后续的处理
				        	int[] arr = new int[length-1];
				        	for(int i = 0 ; i < length-1 ; i++){
				        		arr[i] = Integer.parseInt(ops[i+1]);
				        	}
				            
				        	//此时得到int数组，调用最大子数组问题的递归方法
				        	int[] maxSubArray = findMaximumSubarray(arr,0,length-2);
				        	
				        	System.out.println("Case " + entry.getKey()  + ":");
				        	if(entry.getKey() == rowCount){
				        		System.out.print(maxSubArray[0] + " " + (maxSubArray[1]+1) + " " + (maxSubArray[2]+1));
				        		System.out.println();
				        	}else{
				        		System.out.print(maxSubArray[0] + " " + (maxSubArray[1]+1) + " " + (maxSubArray[2]+1));
				        		System.out.println("\r\n");
				        	}
		                	
		                	
				        }
					}
				}
			}
	}catch(Exception e){
		throw new RuntimeException(e);
	}
  }
	
	public static int[] findMaxCrossingSubarray(int[] arr,int start, int mid,int end) {
		int leftMaxSum = Integer.MIN_VALUE;  //标记数组中左半部分最大值，这个值是一个标记位，为最小值
		int leftCurrentMaxSum = 0 ;  //标记当前和
		int maxLeft = 0;  //标记左边界
		for(int i = mid ; i >= start ; i--){   //从mid分成两个部分讨论，左侧和右侧分别都达到最大，则一整个部分就能达到最大
			leftCurrentMaxSum = leftCurrentMaxSum + arr[i];
			if(leftCurrentMaxSum >= leftMaxSum) {
				leftMaxSum = leftCurrentMaxSum;
				maxLeft = i;
			}
		}
		
		int rightMaxSum = Integer.MIN_VALUE;
		int rightCurrentMaxSum  = 0;
		int maxRight = 0;
		for(int j = mid+1 ; j <= end ; j++) {  // mid右侧部分
			rightCurrentMaxSum = rightCurrentMaxSum + arr[j];
			if(rightCurrentMaxSum >= rightMaxSum) {
				rightMaxSum = rightCurrentMaxSum;
				maxRight = j;
			}
		}//for结束
		
		int[] result = new int[]{leftMaxSum+rightMaxSum,maxLeft,maxRight};   //返回值返回取得最大值时的坐标和最大值
		return result;
	}
	
	public static int[] findMaximumSubarray(int[] arr,int start, int end) {
		int[] result = {};  //初始化
 		if(start == end) {   //base case ，此时只有一个元素，对于一个元素一定是最大的，这是一个平凡的结果
			result = new int[]{arr[start],start,end};
			return result;
		}else{
			int mid = 0;   //将整个问题一分为二，该变量用来记录数组下标的中点
			mid = (start + end) / 2;  //求出中点部分，如果除不尽，整型运算默认采用的是向下取整
			
			int[] left = findMaximumSubarray(arr, start, mid);    //一分为二在左侧寻找最大连续子数组
			int[] right = findMaximumSubarray(arr, mid+1, end);    //一分为二在右侧寻找最大连续子数组
			int[] crossing = findMaxCrossingSubarray(arr, start, mid, end);  //寻找跨越重点的最大连续子数组
			
			
			//对返回的三个结果进行比较
			if (left[0] >= right[0] && left[0] >= crossing[0]) {  //如果最大子数组在左侧部分找到
				result = new int[3];
				result = left;
				return result;
			}else if(right[0] > left[0] && right[0] > crossing[0]){ //如果最大子数组在右侧部分找到
				result = new int[3];
				result = right;
				return right;
			}else{   ////如果最大子数组在穿过中点部分找到
				result = new int[3];
				result = crossing;
				return result;
			}
		}
	}
}

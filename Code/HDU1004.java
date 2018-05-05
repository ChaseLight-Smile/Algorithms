package solution;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.Map;
import java.util.Map.Entry;
import java.util.HashMap;
import java.util.Set;
import java.util.List;
import java.util.ArrayList;
import java.util.Iterator;
/** hdu1004
 * 功能： 找出最流行的颜色
 * @author 朱君鹏
 *
 */
public class HDU1004 {

	public static void main(String[] args){
		//接收键盘输入
		InputStream in = System.in;
		//将字节流转换为字符流
		InputStreamReader input = new InputStreamReader(in);
		//将字节流转换为字符流
		BufferedReader bufferedReader = new BufferedReader(input);
		
		String content = null;
		List<String> list = new ArrayList<String>();
		try{
			while((content = bufferedReader.readLine()) != null){
				//首先读取第一行，第一行输入是测试用例的个数
				int testCaseCount = Integer.parseInt(content);
				Integer maxValue = -1;   //保存最后欢迎的颜色值
				String maxString = null;  //保存最受欢迎的颜色
				if(testCaseCount == 0){
					//System.out.println("最受欢迎的颜色为:" + list);
					//将list中的结果输出
					for(int i = 0 ; i < list.size(); i++){
						System.out.println(list.get(i));
					}
					list.clear();   //清空list
				}else if(testCaseCount > 0 && testCaseCount <= 1000){
					//从输入中读取测试用例	
					int count = 0 ;
					Map<String,Integer> map = new HashMap<String,Integer>();   //采用Map保存输入的气球颜色
					while(count < testCaseCount && (content = bufferedReader.readLine()) != null){  //说明测试用例没有输入结束
						//接收测试用例，之后需要保存
						count++;
						if(map.containsKey(content)){
							Integer value = map.get(content);
							value = value + 1;
							map.put(content,value);
						}else{
							map.put(content,1);  //否则说明第一次出现，此时将直接放入到map中即可
						}
					} //内层while循环结束
					
					//找出map中最受欢迎的颜色
					Set<Map.Entry<String,Integer>> set = map.entrySet();
					//遍历set得到其中的结果，并找到最受欢迎的气球放入到全局List中
					Iterator<Map.Entry<String,Integer>> it = set.iterator();
					while(it.hasNext()){
						Entry<String, Integer> en = it.next();
						en.getKey();
						if(en.getValue() > maxValue){
							maxValue = en.getValue(); 
							maxString = en.getKey(); 
						}
					}
					list.add(maxString);
					map = null;  //将map置空想，下次循环输入时保证Map没有值 
					continue;   //继续接受输入

				}
			}
		}catch(Exception e){
			throw new RuntimeException(e);
		}
		
	}
}

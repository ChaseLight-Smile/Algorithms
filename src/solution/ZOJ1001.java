package solution;

/**
 * 输入流相关OJ题目
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.Iterator;

/** zoj1001 poj1000
 * input： The input will consist of a series of pairs of integers a and b,separated by a space, one pair of integers per line.
 * output: For each pair of input integers a and b you should output the sum of a and b in one line,and with one line of output for each line in input.
 */
public class ZOJ1001 {
	
	public static void main(String[] args) {
		//ZOJ1001Solution();
		//HDU1001Solution();
		HDU1002Solution();
	}
	
	public static void ZOJ1001Solution(){
		//首先获取键盘的输入
		InputStream in = System.in;
		
		//输入是纯文本，采用字符流读取会更加的高效，但是输入时字节流，所以需要使用转换流
		InputStreamReader inputStreamReader = new InputStreamReader(in);
		
		//采用缓存字符流
		BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
		
		//每次读取其中的一行
		String content = null;
		try {
			while((content = bufferedReader.readLine()) != null){
				//整体读取到一行，并保存为String，因为拿空格分割，所以将两个操作数分开采用split函数
				String[] ops = content.split(" ");
				if(ops.length < 2 || ops.length > 2){
					System.out.println("操作数数目不正确请重新输入，操作数个数必须为2，并且用空格分割");
					continue;
				}else {
					//ops数组此时会有两个元素，并且这两个元素将会被作为操作数，但是是否一定是合法的？应该将String转成int
				    int ops1 = Integer.valueOf(ops[0]);   //将String类型转换成Integer，用到了JDK1.5之后的自动拆箱特性将Integer转成int
				    //int ops1 = Integer.parseInt(ops[0]);   //同样可以采用parseInt(String s)函数将字符串转换成整型int
				    int ops2 = Integer.valueOf(ops[1]);
				    System.out.println(ops1+ops2);
				}
				
			}
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}
	
	/** hdu1001
	 * In this problem, your task is to calculate SUM(n) = 1 + 2 + 3 + ... + n.
	 * Input: The input will consist of a series of integers n, one integer per line.
	 * Output: For each case, output SUM(n) in one line, followed by a blank line. You may assume the result will be in the range of 32-bit signed integer.
	 */
	public static void HDU1001Solution(){
		//接收键盘输入
		InputStream in = System.in;
		//采用转换流将字节流转换成字符流
		InputStreamReader input = new InputStreamReader(in);
		//采用缓冲流提高效率
		BufferedReader bufferedReader = new BufferedReader(input);
		
		String content = null;
		//接收键盘的输入并且每次只接收一个数
		try{
			while((content = bufferedReader.readLine()) != null){
				//将content转换为整型
				int number = Integer.parseInt(content);
				int sum = 0 ;
				for(int i = 1 ; i <= number ; i++) {
					sum += i;
				}
				System.out.println(sum);
				System.out.println();  //题目要求后跟一个空行
			}
		}catch(Exception e){
			throw new RuntimeException(e);
		}
	}
	
	/** hdu1002
	 * I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
	 * Input: The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.
	 * Output: For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.
	 * 
	 * 题目的意思是：首先给定一个参数T，决定一次从控制台读取多少行，读完之后对每一行进行加法运算。
     * 经过选择决定采用ArrayList存储，ArrayList底层采用了可变数组进行存储，在我们的需求中，要求能够操作索引值，
     * 在整个集合框架中只有List能操作索引值，其它的没有
     * 在HDU提交时，需要将函数头改为主函数 public static void main(String[] args){}，否则不能正常提交
	*/		
	public static void HDU1002Solution(){
		//首先还是接受键盘输入
		InputStream in = System.in;
		//将字节流转换为字符流
		InputStreamReader input = new InputStreamReader(in);
		//转换为缓冲流，提高效率
		BufferedReader bufferedReader = new BufferedReader(input);
		String content = null ;
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
						
						//分别将String类型的ops[0]和ops[1]拆成一个个的数字，这些数字的范围都是从1到9
						char[] ops1 = ops[0].toCharArray();   //第一个操作数
						char[] ops2 = ops[1].toCharArray();   //第二个操作数
						
						//计算出这两个操作数的length
						int ops1Length = ops1.length ;
						int ops2Length = ops2.length ;
						
						//比较两者的大小，最大的长度+1位和数组的长度，加1是出于可能会有溢出位
						int[] sum = null;
						
						if(ops1Length >= ops2Length){
							sum = new int[ops1Length+1];
						}else{
							sum = new int[ops2Length+1];
						}
						//把长度给两个计数器，计算两个不同数的位数
						int ops1Count = ops1Length-1;
						int ops2Count = ops2Length-1;
						int sumCount = sum.length-1;
						
						while(ops1Count >= 0 && ops2Count >= 0 && sumCount >= 0 ){		
							int add = Character.getNumericValue(ops1[ops1Count]) + Character.getNumericValue(ops2[ops2Count]) + sum[sumCount];
							if(add >= 10){
								sum[sumCount-1] = 1;
								sum[sumCount] = add-10;
								ops1Count--;
								ops2Count--;
								sumCount--;
							}else{
								sum[sumCount] = add;
								ops1Count--;
								ops2Count--;
								sumCount--;
							}
						}
						
						
						if(ops1Count < 0 && ops2Count >= 0){
							//这种情况说明ops1中的数字已经全部被遍历完，但是ops2中的数字还没有被便利完，
							while(ops2Count >= 0 && sumCount >= 0) {
								int add = Character.getNumericValue(ops2[ops2Count]) + sum[sumCount];
								if(add >= 10){
									sum[sumCount-1] = 1;
									sum[sumCount] = add-10;
									ops2Count--;
									sumCount--;
								}else{
									sum[sumCount] = add;
									ops2Count--;
									sumCount--;
								}
							}
						}
						
						if(ops2Count < 0 && ops1Count >= 0){
							//这种情况说明ops2中的数字已经全部被遍历完，但是ops1中的数字还没有被遍历完，
							while(ops1Count >= 0 && sumCount >= 0) {
								int add = Character.getNumericValue(ops1[ops1Count]) + sum[sumCount];
								if(add >= 10){
									sum[sumCount-1] = 1;
									sum[sumCount] = add-10;
									ops1Count--;
									sumCount--;
								}else{
									sum[sumCount] = add;
									ops1Count--;
									sumCount--;
								}
							}
						}
						
		               
	                	System.out.println("Case " + entry.getKey()  + ":");
	                	if(entry.getKey() == map.size()) {
	                		System.out.print(ops[0] + " + " + ops[1] + " = " );
		                	if(sum[0] == 0){
		                		for(int j = 1; j < sum.length; j++){
		                			System.out.print(sum[j]);
		                		}
		                		System.out.print("\r\n");
		                	}else{
		                		for(int j = 0; j < sum.length; j++){
		                			System.out.print(sum[j]);
		                		}
		                		System.out.print("\r\n");
		                	}	
	                	}else{
	                		System.out.print(ops[0] + " + " + ops[1] + " = " );
		                	if(sum[0] == 0){
		                		for(int j = 1; j < sum.length; j++){
		                			System.out.print(sum[j]);
		                		}
		                		System.out.println("\r\n");
		                	}else{
		                		for(int j = 0; j < sum.length; j++){
		                			System.out.print(sum[j]);
		                		}
		                		System.out.println("\r\n");
		                	}	
	                	}
	                	
					}
				}else{
					System.out.println("请重新输入行数，范围要求在1-20之间");
					continue;
				}
			}
		}catch(Exception e){
			throw new RuntimeException();
		}	
	}
}

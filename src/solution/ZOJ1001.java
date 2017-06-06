package solution;

/**
 * 输入流相关OJ题目
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/** zoj1001 poj1000
 * input： The input will consist of a series of pairs of integers a and b,separated by a space, one pair of integers per line.
 * output: For each pair of input integers a and b you should output the sum of a and b in one line,and with one line of output for each line in input.
 */
public class ZOJ1001 {
	
	public static void main(String[] args) {
		//ZOJ1001Solution();
		HDU1001Solution();
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
	 */
	public void HDU1002Solution(){
		//题目的意思是：首先给定一个参数T，决定一次从控制台读取多少行，读完之后对每一行进行加法运算。需要注意的是: 整数不能由普通的int来存储，题目中假设整数
		//长度不会超过1000位，所以衡量之后，决定采用数组进行存储。数组方案不好，因为输入整数的长度是可变的，需要使用集合数据类型存储，采用数组会存在极大的
		//空间浪费
		
	}
}

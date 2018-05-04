package solution;

import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.List;
import java.util.ArrayList;
/**
 * hdu1005
 * 缺点： 普通递归算法很耗内存，需要修改，将其修改为尾递归
 * @author 朱君鹏
 */
public class HDU1005 {
	public static void main(String[] args) {
		InputStream in = System.in;
		// 将键盘输入字节流转换为字符流
		InputStreamReader input = new InputStreamReader(in);
		// 使用缓冲流提高读取效率
		BufferedReader reader = new BufferedReader(input);

		String content = null;
		List<Integer> list = new ArrayList<Integer>();
		try {
			while ((content = reader.readLine()) != null) {
				String[] ops = content.split(" ");
				int count = 0;
				for (String s : ops) {
					int num = Integer.parseInt(s);
					if (num == 0) {
						count++;
					}
				}
				if (count == ops.length) {
					// 说明此次输入全部为0，在此部分进行输出操作
					for(int i = 0 ; i < list.size() ; i++){
						System.out.println(list.get(i));
					}
					list.clear();
					// 输出完之后继续接受输入
					continue;
				} else {
					// 说明输入不全为0，此时进行处理
					//首先得到三个操作数
					int a = Integer.parseInt(ops[0]);
					int b = Integer.parseInt(ops[1]);
					int n = Integer.parseInt(ops[2]);
					/*int result = sumRecursive(a,b,n);*/
					int result = sumTailRecursive(a,b,n,1,2%7);
					list.add(result);
				}
			}
		} catch (Exception e) {

		}
	}
	
	/**  普通递归，不是尾递归，尾递归的判断标准是: 函数运行的最后一步是否调用自身，而不是是否在函数的最后一行调用自身
	 * 递归算法很耗费内存，耗费内存同时相当于耗费时间，这与计算机的内存分配机制有关
	 * @param a  表达式计算时的系数a
	 * @param b  表达式计算时的系数b
	 * @param n  表达式计算第n项的结果
	 * @return   返回最后的计算结果
	 */
	public static int sumRecursive(int a , int b , int n){
		if(n == 1 || n == 2){
			return 1;
		}
		// (A * f(n - 1) + B * f(n - 2)) mod 7.
		return (a * sumRecursive(a,b,n-1) + b * sumRecursive(a,b,n-2)) % 7;  //非尾递归，该函数的最后一步是加法，不是函数自身的调用，所以不是尾递归
	}
	
	/** 将上述的递归改写成尾递归，尾递归只存在一个调用记录，下面代码是正确的尾递归形式，但是空间复杂度仍然超过阈值
	 * 优于Java编译器的问题，不会讲尾递归自动转化为循环(迭代)，所以需要手动的实现尾递归向迭代的转换，才能将空间复杂度降下来
	 * @param a 固定
	 * @param b 固定
	 * @param n 随着规模的变化而减小
	 */
	public static int sumTailRecursive(int a , int b , int n, int result1,int result2){
		if(n == 1 || n == 2){
			return result1;
		}
		return sumTailRecursive(a, b, n-1, result2, (a*result1+b*result2)%7);
	}
}

package solution;

import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.List;
import java.util.ArrayList;
/**
 * hdu1005
 * 
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
					int result = sum(a,b,n);
					list.add(result);
				}
			}
		} catch (Exception e) {

		}
	}
	
	/**  尾递归，能够采用法则去掉递归降低内存使用
	 * 递归算法很耗费内存，耗费内存同时相当于耗费时间，这与计算机的内存分配机制有关
	 * @param a  表达式计算时的系数a
	 * @param b  表达式计算时的系数b
	 * @param n  表达式计算第n项的结果
	 * @return   返回最后的计算结果
	 */
	public static int sum(int a , int b , int n){
		int result = 0;
		if(n == 1 || n == 2){
			result = 1;
			return result;
		}else{
			// (A * f(n - 1) + B * f(n - 2)) mod 7.
			result = (a * sum(a,b,n-1) + b * sum(a,b,n-2)) % 7;
			return result;
		}
	}
}

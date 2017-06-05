package solution;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/** zoj1001 poj1000
 * input： The input will consist of a series of pairs of integers a and b,separated by a space, one pair of integers per line.
 * output: For each pair of input integers a and b you should output the sum of a and b in one line,and with one line of output for each line in input.
 * @author 朱君鹏
 *
 */
public class ZOJ1001 {
	
	public static void main(String[] args) {
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
				//ops数组此时会有两个元素，并且这两个元素将会被作为操作数，但是是否一定是合法的？应该讲String转成Integer
			    int ops1 = Integer.valueOf(ops[0]);
			    int ops2 = Integer.valueOf(ops[1]);
			    
			    System.out.println(ops1+ops2);
			}
		} catch (IOException e) {
			throw new RuntimeException();
		}
	}
}

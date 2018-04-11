package solution;

import java.math.BigDecimal;

/*
 * 1. 需求一：产生区间[a,b)上的任意的随机数，过程如下:
 * length = (b-a);
 * range = Math.random() * (b-a);   // 得到的数据范围为[0,b-a)
 * range+a;   //我们发现range+a = [0,b-a) + a = [a,b)
 * 2. 需求二：产生区间[a,b]上的任意的随机数，过程如下:
 * length = (b-a);
 * range = Math.random() *{(b-a) + 1}   //得到的数据范围为[0,b-a]，或者是[0,b-a+1)
 * range+a; //得到想要的范围
 * 3. Math.random()函数产生的随机数满足均匀分布，随机算法需要用到随机数生成
 */
public class Random {
	public static void random(){
		//测试java自带的随机数生成器
		for(int i = 0 ; i < 10 ; i++){
			int random1 = (int)(Math.random()*10);  //返回double随机数，并且返回的随机数在[0.0-1.0)之间，不包含1.0，乘10之后，将其转成整型
			                                        //并且数字的范围在[0-10)之间，不包含10,
			int random2 = (int)(Math.random()*100+1);   //产生1到100之间的数字，采用这样的方法能产生任意范围内的数字
			System.out.println(random1);
		    System.out.println(random2);
		}
		
		//对double类型数据进行取余操作的测试
		double k =  15.2;
		double j = 2;
		System.out.println(new BigDecimal(k%j).floatValue());  //这个结果仍然是float类型，大部分情况下我们需要余数是整型
		System.out.println((int)(k % j ));
	}
	
	public static void main(String[] args) {
		random();
	}
}

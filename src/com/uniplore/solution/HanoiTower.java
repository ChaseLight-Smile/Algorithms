package com.uniplore.solution;

/**
 * 问题描述: 传说婆罗门庙里有一个塔台，台上有3个标号为A,B,C的用钻石做成的柱子，在A柱子上放着64个金盘，每一个都比下面的略小一点
 * 把A柱子上的所有金盘全部移动到C柱子上的那一天就是世界末日，移动的条件是: 每次只能移动一个金盘，移动过程只不过大金盘不能放在小
 * 金盘的上面。庙里的僧人一直移动个不停，因为全部的移动是2^63次方，如果每秒移动一次的话，需要500亿年，但是一位计算机科学家提出了
 * 一种快速求解Hanoi塔问题的递归解法。该过程采用输出语句模拟整个过程，每一次输出实际上都是一个移动的操作，请按照输出的顺序进行操作
 * 一定能够完成所有的移动. 请一定要注意: Hanoi塔问题只能使用递归解法，如果你想快速给出一个当n=任何一个数时的放置顺序，请在主函数
 * 中变换n的值
 * @author 朱君鹏
 *
 */
public class HanoiTower {
	public static void Hanoi(int n ,String A, String B, String C ){
		if(n == 1){
			System.out.println("请移动"+A+"柱子上的一个金盘到"+C+"柱子上");
		}else{
			Hanoi(n-1,A,C,B);
			System.out.println("请移动"+A+"柱子上的一个金盘到"+C+"柱子上");
			Hanoi(n-1,B,A,C);
		}
	}
	public static void main(String[] args) {
		/*int n = 3;*/
		/** 下面的7步操作是当有3个金盘时，控制台的输出语句，
		 * 请按照1-7的步骤操作一个n=3时具体的过程，
		 * 看是否能够实现目标(回答是肯定的)
		    1.请移动A柱子上的一个金盘到C柱子上
			2.请移动A柱子上的一个金盘到B柱子上
			3.请移动C柱子上的一个金盘到B柱子上
			4.请移动A柱子上的一个金盘到C柱子上
			5.请移动B柱子上的一个金盘到A柱子上
			6.请移动B柱子上的一个金盘到C柱子上
			7.请移动A柱子上的一个金盘到C柱子上
		 */
		int n = 4;
		String aString = "A";
		String bString = "B";
		String cString = "C";
		Hanoi(n, aString, bString, cString);
	}
}

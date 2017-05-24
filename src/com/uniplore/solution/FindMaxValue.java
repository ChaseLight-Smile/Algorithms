package com.uniplore.solution;

/**
 * 功能: 寻找一个数组中的全局最大值，时间代价就是扫描一个数组的时间O(n)
 * @author 朱君鹏
 *
 */
public class FindMaxValue {
  
	public static int findMaxValue(int[] arr) {
		int length = arr.length;   //首先获取数组的最大长度
		int max = arr[0];
		for (int i = 1; i < length; i++){    //这个过程的代价其实就是扫描数组的代价 O(n)
			if(max < arr[i]){   //如果最大值比当前元素小，则将当前元素的值复制给最大值
				max = arr[i];   //将当前的值赋值给max
			}else {
				continue;
			}
		}
		return max;
	}
	public static void main(String[] args) {
		//int[] arr = {2,4,3,1,5,6,0,-1} ;   //测试组1
		//int[] arr = {2,-1,-2};   //测试组2
		int[] arr = {5,4,3,2,1,-1};   //测试组3
		System.out.println(findMaxValue(arr));
	}
}

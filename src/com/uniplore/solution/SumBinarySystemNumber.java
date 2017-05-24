package com.uniplore.solution;

/**
 * 功能: 考虑把两个n位二进制整数加起来，这两个整数分别存储在两个n元数组A和B当中。这两个整数的和应该按照二进制形式存储在一个(n+1)
 * 元数组C中.
 * @author 朱君鹏
 *
 */
public class SumBinarySystemNumber {

	public static void sumBinarySystemNumber(int[] addNumber1,int[] addNumber2) {
		//将两个加数数组在最前面分别各自都补一个0，使得整个加数、和这三个数组的位数是一样的
		int sumLength = addNumber1.length + 1;            //设置新的加数数组的长度
		int[] addNumber1Extends =  new int[sumLength];   //构造新的加数数组
		int[] addNumber2Extends =  new int[sumLength];   //构造新的加数数组
		
		//构造新的数组
		for (int i = 0 ; i < sumLength ; i++) {
			if(i == 0) {
				addNumber1Extends[i] = 0;
				addNumber2Extends[i] = 0;
			}else {
				addNumber1Extends[i] = addNumber1[i-1];
				addNumber2Extends[i] = addNumber2[i-1];
			}
		}
		
	    //遍历新构造的加数数组
		/*for (int i : addNumber1Extends){
			System.out.print(i + " ");
		}*/
		
		//System.out.println();
		/*for (int i : addNumber2Extends){
			System.out.print(i + " ");
		}*/
		
		//System.out.println();
	    //构造和数组
		int[] sum = new int[sumLength];
		
		//遍历和数组
		/*for (int i : sum) {
			System.out.print(i + " ");
		}*/
		
		//开始判断逻辑
		for(int i = sumLength-1;i >= 0; i--){
			int key = addNumber1Extends[i] + addNumber2Extends[i] + sum[i];
			switch (key) {
			case 0:
				sum[i] = 0;
				break;
			case 1:
				sum[i] = 1;
				break;
			case 2:
				sum[i-1] = 1;
				sum[i] = 0;
				break;
			case 3:
				sum[i-1] = 1;
				sum[i] = 1;
				break;
			}
		}
		
		//遍历和数组
		for (int i : sum) {
			System.out.print(i + " ");
		}
	}
	
	public static void main(String[] args) {
		//测试组1
		//int[] arr1 = {1,0};
		//int[] arr2 = {1,1};
		int[] arr1 = {1,0,1,1};
		int[] arr2 = {1,1,1,1};
		sumBinarySystemNumber(arr1, arr2);
	}
}

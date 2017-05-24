package com.uniplore.solution;

/**
 * 功能: 寻找一个数组中一个局部最大值，请注意，该数组中不一定只有一个局部最大值，但是我只需要寻找一个局部最大值即可
 * 局部最大值的定义：a[i]是局部最大值 if, and if  a[i] >= a[i-1] and a[i] > a[i+1]; 
 * 该算法的时间复杂度为O(logN)  N表示数组的长度
 * @author 朱君鹏
 *
 */
public class FindLocalPeakOneVersion {
  
	public static int findLocalPeakOneVersion(int[] arr,int start , int end){  
		
		//获取到数组的长度
		int length = arr.length;
		
		//找到数组中中间位置的值
		int mid = (start + end) / 2;
		
		//递归结束的条件
		if (mid != length-1 && arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
			return arr[mid];
		}
		
		//递归结束的条件
		if (mid == length-1 && arr[mid] > arr[mid-1]) {
			return arr[mid];
		}
		
		if(arr[mid] < arr[mid-1]) {
			return findLocalPeakOneVersion(arr,0,mid-2);
		} else {
			return findLocalPeakOneVersion(arr, mid+1, length-1);
		}
	}
	
	public static void main(String[] args) {
		//int[] arr = {1,2,5,4,3};   //测试组1
		//int[] arr = {1,2,3,4,5};   //测试组2
		int[] arr = {-1,2,3,10,100,6,4,3,2,1000};  //测试组3
		int length = arr.length;
		System.out.println(findLocalPeakOneVersion(arr,0,length-1));
	}
}

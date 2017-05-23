package com.uniplore.problemset1;

public class MergeSort {

	public static int[] mergeSort(int[] arr , int start ,int end) {
		if(start < end) {
			int mid = ((start + end) / 2 );
			int[] leftArray = mergeSort(arr, start, mid);   //排序左边的部分
			int[] rightArray = mergeSort(arr, mid + 1, end);  //排序右边的部分
			
			int[] result = Merge.merge(leftArray, rightArray);
			return result;
		}
		int[] result = {arr[start]};
		return result;
		
	}
	
	public static void main(String[] args) {
		//int[] arr = {2,4,5,7,1,2,3,6};  //测试组1
		//int[] arr = {7,6,5,4,3,2,1};  //测试组2
		int[] arr = {3,41,52,26,38,57,9,49};  //测试组2
		int length = arr.length;
		int[] mergeSort = mergeSort(arr, 0, length-1);  //从0开始计数
		//System.out.println(mergeSort.length);
		for (int a : mergeSort) {
			System.out.print(a+ " ");
		}
	}
}

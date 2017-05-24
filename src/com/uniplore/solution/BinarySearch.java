package com.uniplore.solution;

public class BinarySearch {

	public static boolean binarySearch(int[] arr,int start,int end , int target){
		InsertSort.insertSort(arr);  // 将数组排序
		if (start == end && target != arr[start]) {
			System.out.println("找不到对应的元素");
			return false;
		}
		
		int mid = (start + end) / 2;  //找到数组的中间位置
		if (target == arr[mid]) {
			System.out.println("找到对应的元素");
			return true;
		}else if(target > arr[mid]) {
			binarySearch(arr, mid+1, end, target);
		}else if(target < arr[mid]){
			binarySearch(arr, 0, mid-1, target);
		}
		return false;
	}
	
	public static void main(String[] args) {
		int[] arr = {-1,2,100,-100,30,-23,90};
		//binarySearch(arr, 0, arr.length-1, -10);   //测试组1
		//binarySearch(arr, 0, arr.length-1, 1000);  //测试组2
		binarySearch(arr, 0, arr.length-1, 10000);     //测试组3
	}
}

package com.uniplore.solution;

public class BinarySearch {

	public static boolean binarySearch(int[] arr,int start,int end , int target){
		boolean result = false ;
		if (start == end && target != arr[start]) {
			System.out.println("找不到对应的元素");
			result = false;
			return result;
		}
		
		int mid = (start + end) / 2;  //找到数组的中间位置
		if (target == arr[mid]) {
			System.out.println("找到对应的元素");
			result = true;
			return result;
		}else if(target > arr[mid]) {
			result = binarySearch(arr, mid+1, end, target);
		}else if(target < arr[mid]){
			result = binarySearch(arr, 0, mid-1, target);
		}
		return result;
	}
	
	public static void main(String[] args) {
		int[] arr = {-1,2,100,-100,30,-23,90};
		//binarySearch(arr, 0, arr.length-1, -10);   //测试组1
		//binarySearch(arr, 0, arr.length-1, 1000);  //测试组2
		InsertSort.insertSort(arr);  // 将数组排序
		boolean binarySearch = binarySearch(arr, 0, arr.length-1, 10000);     //测试组3
		System.out.println(binarySearch);
	}
}

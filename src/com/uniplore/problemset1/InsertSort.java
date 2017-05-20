package com.uniplore.problemset1;

/**
 * 功能: 插入排序思想很简单，假设要将一个数组按非递减顺序排序，那么首先假设从左到右以此都是排序好的，从第二个元素开始与其左侧位置进行比较，并将
 * 该元素放置在合适的位置上，该算法最坏情况下的时间复杂度为O(n^2)，n为输入规模
 * @author 朱君鹏
 *
 */
public class InsertSort {

	public static void insertSort(int[] arr) {
		int length = arr.length;
		for (int i = 1;i < length ; i++) {
			for (int j = 0 ; j < i ; j++) {
				if (arr[i] < arr[j]) {
					int temp;
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
				else{
					continue;
				}
			}
		}
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}
	
	public static void main(String[] args) {
		//int[] arr = {5,4,3,2,1};  //测试组1
		int[] arr = {5,2,4,6,1,3};
		insertSort(arr);
	}
}

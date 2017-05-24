package com.uniplore.solution;

/**
 * LeetCode第一题，该算法的时间复杂度是O(n)，已经算目前能想到的相当不错的算法了，当然还有其它的O(nlogn)的算法
 */
import java.util.HashMap;
import java.util.Map;

public class AddTwoNumbers {

	public static int[] twoSum(int[] nums, int target) {
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		int length = nums.length;
		for (int i = 0 ; i < length ; i++){
			map.put(nums[i], i);   //存放值与位置的对应
		}
		
		for(int j = 0 ; j < length ; j++) {
			int key = target - nums[j];
			if (map.containsKey(key)) {
				int value = map.get(key);
				if(value != j){
					return new int[]{j,value};
				}else{
					continue;
				}
				
			}
		}
		return new int[]{-1,-1};   //否则说明不存在
	}
	
	public static void main(String[] args) {
		//int[] nums = {2,7,11,15};
		int[] nums = {3,2,4};
		/*int[] twoSum = twoSum(nums, 9);*/
		int[] twoSum = twoSum(nums, 6);
		int[] twoSum1 = twoSum1(nums, 6);
		for (int i : twoSum) {
			System.out.println(i + " ");
		}
		for (int i : twoSum1) {
			System.out.println(i + " ");
		}
	}
	
	public static int[] twoSum1(int[] nums, int target) {
		//该算法的时间复杂度是O(nlogn)
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		int length = nums.length;
		for (int i = 0 ; i < length ; i++){
			map.put(nums[i], i);   //存放值与位置的对应
		}
		
		//将整个数组排序
		int[] mergeSort = MergeSort.mergeSort(nums, 0, length-1);
		for (int j = 0 ; j < length ; j++) {
			int key = target - mergeSort[j];
			System.out.println("key:" + " " + key);
			boolean flag = BinarySearch.binarySearch(mergeSort, 0, length - 1 , key);
			if(flag) {
				int value = map.get(key);
				System.out.println("value:" + " " + value);
				return new int[]{j,value};
			}else{
				continue;
			}
		}
		return new int[]{-1,-1};
	}
}

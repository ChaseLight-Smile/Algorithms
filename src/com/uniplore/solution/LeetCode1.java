package com.uniplore.solution;

import java.util.HashMap;
import java.util.Map;

/**
 * 功能: Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Given nums = [2, 7, 11, 15], target = 9, Because nums[0] + nums[1] = 2 + 7 = 9, return [0, 1]
 * @author 朱君鹏
 * 说明： 该算法能保证找到正确的答案，但是在LeetCode上没有提交成功，原因是19个测试用例18个通过，但是有一个超时
 */
public class LeetCode1 {
	
	public static int[] twoSum(int[] nums, int target) {
		int length = nums.length;
		//申请一个二维数组，二维数组的维度大小已经确定，平凡方法，性能差，需要O(n^2)
		int[][] arr = new int[length][length];
		int[] result = new int[2];
		int i = 0;  
		int j = 0;
		for ( i = 0 ; i < length ; i++) {
			for (j = 0 ; j < length ; j++){
			    if( i == j) {
			        continue;
			    } else{
			        arr[i][j] = nums[i] + nums[j];
				    if(arr[i][j] == target){
					    result[0]=i;
					    result[1]=j;
					    return result;
				    }else{
					    continue;
				    }
			    }
			    
			}
		}
		return result;
	}
	
	//线性时间复杂度O(n)
	public int[] twoSum1(int[] nums, int target) {
        int[] result = new int[2];
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
				    result[0] = j;
				    result[1] = value;
				    return result;
				}else {
				    continue;
				}
				
			}
		}
		return result;   //否则说明不存在
    }
	
	public static void main(String[] args) {
		int[] arr = {2,7,11,15,21,46,43,1};
		int[] twoSum = twoSum(arr, 3);
		for (int i : twoSum) {
			System.out.print(i + " ");
		}
	}
}

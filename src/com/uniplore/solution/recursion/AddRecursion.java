package com.uniplore.solution.recursion;

public class AddRecursion {
	public static int addrRecursion(int[] nums, int length){
		int sum = 0 ;
		if(length == 1) {
			sum += nums[0];
			return sum;
		}
		
		sum = addrRecursion(nums, length-1) + nums[length-1];
		return sum;
	}
	
	public static void main(String[] args) {
		int[] nums = {1,2,3,4,5,6,7,8,9,10};
		int length = nums.length;
		int sum = addrRecursion(nums, length);
		System.out.println(sum);
	}
}

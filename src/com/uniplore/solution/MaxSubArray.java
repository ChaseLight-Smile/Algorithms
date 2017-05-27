package com.uniplore.solution;

import org.junit.Test;

/**
 * 功能: 采用分治法求解最大子数组问题，最大子数组下标必须是连续的，并且从分治的角度上讲: 以数组下标的中点为分界点，会被分成两个部分，
 * 那么最大连续子数组一定只能出现在三个位置: 中点分界线左侧，中点分界线右侧，跨越中点。对于中点分界线左侧和中点分界线右侧的情况，实际
 * 上和原问题相比只是规模变小，但是问题的本质还是一样的，只有跨越中点的情况和其余的两个子问题本质完全不同，但是跨越中点的子问题我们可以
 * 在O(n)时间内解决，函数findMaxCrossingSubarray解决了这个子问题。
 * @author 朱君鹏
 *
 */
public class MaxSubArray {

	//寻找跨越中点的最大连续子数组，该数组必须要包含mid，并且数组要连续
	public static int[] findMaxCrossingSubarray(int[] arr,int start, int mid,int end) {
		int leftMaxSum = -1000000000;  //标记数组中左半部分最大值，这个值是一个标记位，为最小值
		int leftCurrentMaxSum = 0 ;  //标记当前和
		int maxLeft = 0;  //标记左边界
		for(int i = mid ; i >= start ; i--){   //从mid分成两个部分讨论，左侧和右侧分别都达到最大，则一整个部分就能达到最大
			leftCurrentMaxSum = leftCurrentMaxSum + arr[i];
			if(leftCurrentMaxSum > leftMaxSum) {
				leftMaxSum = leftCurrentMaxSum;
				maxLeft = i;
			}
		}
		
		int rightMaxSum = -1000000000;
		int rightCurrentMaxSum  = 0;
		int maxRight = 0;
		for(int j = mid+1 ; j <= end ; j++) {  // mid右侧部分
			rightCurrentMaxSum = rightCurrentMaxSum + arr[j];
			if(rightCurrentMaxSum > rightMaxSum) {
				rightMaxSum = rightCurrentMaxSum;
				maxRight = j;
			}
		}//for结束
		
		int[] result = new int[]{maxLeft,maxRight,leftMaxSum+rightMaxSum};   //返回值返回取得最大值时的坐标和最大值
		return result;
	}
	
	
	//递归的解寻找最大子数组问题，只要给定一个出口即可，时间复杂度为O(nlogn)
	public static int[] findMaximumSubarray(int[] arr,int start, int end) {
		int[] result = {};  //初始化
 		if(start == end) {   //base case ，此时只有一个元素，对于一个元素一定是最大的，这是一个平凡的结果
			result = new int[]{start,end,arr[start]};
			return result;
		}else{
			int mid = 0;   //将整个问题一分为二，该变量用来记录数组下标的中点
			mid = (start + end) / 2;  //求出中点部分，如果除不尽，整型运算默认采用的是向下取整
			
			int[] left = findMaximumSubarray(arr, start, mid);    //一分为二在左侧寻找最大连续子数组
			int[] right = findMaximumSubarray(arr, mid+1, end);    //一分为二在右侧寻找最大连续子数组
			int[] crossing = findMaxCrossingSubarray(arr, start, mid, end);  //寻找跨越重点的最大连续子数组
			
			
			//对返回的三个结果进行比较
			if (left[2] >= right[2] && left[2] >= crossing[2]) {  //如果最大子数组在左侧部分找到
				result = new int[3];
				result = left;
				return result;
			}else if(right[2] >= left[2] && right[2] >= crossing[2]){ //如果最大子数组在右侧部分找到
				result = new int[3];
				result = right;
				return right;
			}else{   ////如果最大子数组在穿过中点部分找到
				result = new int[3];
				result = crossing;
				return result;
			}
		}
	}
	
	//平凡方法寻找最大子数组，时间复杂度为O(n^2)
	public static int trivialFindMaximumSubarray(int[] arr){
		int length = arr.length;
		int maxSum = -1000000000;
		int[] max = new int[length];
		for(int i = 0 ; i < length; i++){
			maxSum = arr[i];
			int sum = 0 ;
			for(int j = i+1 ; j < length ; j++){
				/*for(int k = i ; k <= j ; k++){
					sum += arr[k];
				}*/   //如果采用这个代码，时间复杂度为O(n^3)
				sum += arr[j];  //采用该句代码替换上面注释的部分
				if (sum > maxSum) {
					maxSum = sum;
			    }else{
			    	continue;
			    }
			}
			max[i] = maxSum;
		}
		int[] mergeSort = MergeSort.mergeSort(max, 0,length-1);
		maxSum = mergeSort[length-1];
		return maxSum;
	}
	
	@Test
	public void testFindMaxCrossingSubarray() throws Exception {
		int[] arr = {13,-2,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
		int length = arr.length;
		int mid = (0+length-1)/2;
		int[] findMaxCrossingSubarray = findMaxCrossingSubarray(arr, 0, mid, length-1);
		for (int i : findMaxCrossingSubarray) {
			System.out.print(i + " ");
		}
	}
	
	public static void main(String[] args) {
		//int[] arr = {13,-2,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};  //测试组1
		//int[] arr = {1,-4,3,-4};   //测试组2
		//int[] arr = {1,2,3,4};  //测试组3
		int[] arr = {-1,-2,-3,-4};  //测试组4
		//int[] arr = {13,-3,-25,20};   //测试组5
		int length = arr.length;
		int[] findMaximumSubarray = findMaximumSubarray(arr, 0, length-1);
		System.out.println("平凡方法得到的最大值为:" + trivialFindMaximumSubarray(arr));		
		System.out.println("非平凡方法得到的最大值为:" + findMaximumSubarray[2]);
	}
}

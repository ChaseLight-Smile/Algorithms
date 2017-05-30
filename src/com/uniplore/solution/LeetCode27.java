package com.uniplore.solution;

import java.util.ArrayList;
import java.util.List;

public class LeetCode27 {

	public int removeElement(int[] nums, int val) {
		int length = nums.length;

		List<Integer> list = new ArrayList<Integer>();

		for (int i = 0; i < length; i++) {
			if (nums[i] != val) {
				list.add(nums[i]);
			} else {
				continue;
			}
		}

		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i));
			nums[i] = list.get(i);
		}

		return list.size();
	}
}

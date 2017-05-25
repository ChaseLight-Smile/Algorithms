package com.uniplore.solution;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class Add3Numbers {
	
	//时间复杂度不好，有待提高，代码只能得出争取的答案
    public static  List<List<Integer>> threeSum(int[] nums) {
        int length = nums.length;
        List<List<Integer>> result = new ArrayList<List<Integer>>();
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i = 0 ; i < length ; i++){
            map.put(nums[i],i+1);
        }
        
        //开始一个两层的循环
        Map<Set,Integer> hashMap = new HashMap<Set,Integer>();
        for(int j = 0 ; j < length ; j++) {
            for(int k = 0 ; k < length ; k++) {
                Integer key = -1 * (nums[j] + nums[k]);
                
                Integer value = map.get((key));  //一定要用Integer，包装类
                
                if(map.containsKey(key) && value != null && j != k && k != (value-1) && j != (value-1) ){
                    List<Integer> list = new ArrayList<Integer>();
                    list.add(nums[j]);
                    list.add(nums[k]);
                    list.add(key);
                    HashSet s1 = new HashSet(list);  //将list转换成HashSet，因为set本身是无顺序的
                    if(hashMap.containsKey(s1)) {
                        continue;
                    }else{
                        result.add(list);
                        hashMap.put(s1,k);
                    }
                }else{
                    continue;
                }
            }
        }
        return result;
    }
    
    public static void main(String[] args) {
		int[] nums = {-1,0,1,2,-1,-4};
		List<List<Integer>> threeSum = threeSum(nums);
		for (List<Integer> list : threeSum) {
			System.out.print(list + " ");
		}
	}
}

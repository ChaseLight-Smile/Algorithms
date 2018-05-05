package solution;

import java.util.HashMap;
import java.util.Map;

import sun.security.util.Length;

/**
 * 功能: 寻找一个数组中一个局部最大值，请注意，该数组中不一定只有一个局部最大值，但是我只需要寻找一个局部最大值即可
 * 局部最大值的定义：a[i]是局部最大值 if, and if  a[i] >= a[i-1] and a[i] > a[i+1]; 
 * 该算法的时间复杂度为O(logN)  N表示数组的长度
 * @author 朱君鹏
 *
 */
public class FindLocalPeakOneVersion {
  
	//递归算法实现寻找局部最大值点问题，这个问题其实很不适合写递归算法，下面的非递归算法效果极佳，这样写递归算法很复杂，边界处理和测试都难
	//但是时间复杂度为O(logn)，非递归算法的时间复杂度为O(n)，递归算法明显时间复杂度更低
	public static int findLocalPeakOneVersion(int[] arr,int start , int end){  
		//采用二分法的思想
		int length = arr.length;
		int mid = (start+end)/2;
		int result = -1;
		
		if(mid == 0 && length == 1){
			result = 0;
			return result;
		}else if(mid == 0 && length > 1 ){
			if(arr[mid] > arr[mid+1]){
				result = mid;
				return mid;
			}
		}
		
		if(mid == length -1 && arr[mid] > arr[mid-1]){
			result = mid;
			return result;
	    }
		
		if(mid != 0 && arr[mid] > arr[mid+1] && arr[mid] > arr[mid-1]){
			result = mid;
			return result;
		}else if(mid != 0 && arr[mid] < arr[mid-1]){
			result =  findLocalPeakOneVersion(arr, start, mid-1);
			return result;
		}else if(arr[mid] < arr[mid+1]){
			result = findLocalPeakOneVersion(arr, mid+1, end);
			return result;
		}
		return result;
	}
	
	//非递归版本寻找局部最小值点算法
	public static int findPeakElement(int[] nums) {
        int length = nums.length;
        int result = -1;
        
        //当只有一个元素时，该值就是局部最大值
        if(length == 1){
            result = 0;
            return result;
        }
        
        
        if(nums[0] > nums[1]){
            result = 0;
            return result;   //说明0位置是局部最大值点
        }
        
        if(nums[length-1] > nums[length-2]){
            result = length - 1 ;
            return result;  //说明最后一个位置为最大值点
        }
        
        //将所有元素放到map中，下标为key，值为value
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        
        for(int i = 0 ; i < length; i++) {
            map.put(i,nums[i]);
        }
        
        for(int i  = 1 ; i < length-1 ; i++){
            int value1 = map.get(i-1);
            int value2 = map.get(i+1);
            if(nums[i] > value1 && nums[i] > value2){
                result = i ;
                return result;
            }else{
                continue;
            }
        }
        return result;
    }
	
	public static void main(String[] args) {
		int[] arr = {1,2,5,4,3};   //测试组1
		//int[] arr = {1,2,3,4,5};   //测试组2
		//int[] arr = {-1,2,3,10,100,6,4,3,2,1000};  //测试组3
		//int[] arr = {1,2,3,1};
		//int[] arr = {1};
		//int[] arr = {1,2};
		//int[] arr = {2,1};
		//int[] arr = {3,2,1};
		int length = arr.length;
		System.out.println(findPeakElement(arr));
		System.out.println(findLocalPeakOneVersion(arr,0,length-1));
	}
}

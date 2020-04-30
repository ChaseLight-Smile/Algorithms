//解法一： hash table 空间复杂度为O(n)
public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[]{-1,-1};
        int length = numbers.length;
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        for(int i = 0; i < length ; i++ ){
            map.put(numbers[i],i);
        }
        
        for(int j = 0 ; j < length ; j++) {
            if(map.containsKey(target-numbers[j])){
                result[0] = j+1;
                result[1] = map.get(target-numbers[j])+1;
                return result;
            }else{
                continue;
            }
        }
        
        return result;
    }
}

//二分检索方法
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        if(len == 0){
            return {-1,-1};
        }
        for(int i = 0; i < len-1; i++){
            int right = findTarget(numbers, target-numbers[i], i+1, len-1);
            if(right != -1){
                return {i+1, right+1};
            }
        }
        return {-1,-1};
    }
    int findTarget(vector<int>& nums, int target, int start, int end){
        int left = start;
        int right = end;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        if(nums[left] == target){
            return left;
        }
        return -1;
    }
};

//双指针，相向型指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int left = 0 ;
        int right = len-1;
        while(left < right){
            if(numbers[left] + numbers[right] > target){
                --right;
            }else if(numbers[left] + numbers[right] < target){
                ++left;
            }else{
                return {left+1, right+1};
            }
        }
        return {-1,-1};
    }
};
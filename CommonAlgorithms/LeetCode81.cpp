//解法一：采用二分包含验证法
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        int first = 0;
        int last = len-1;
        int mid = 0;
        while(first < last){
            mid = (first + last)/2;
            if(target == nums[mid]){
                return true;
            }
            if(target < nums[mid]){
                last = mid-1;
                mid = (first+last)/2;
            }
            
            if(target > nums[mid]){
                first = mid+1;
                mid = (first+last)/2;
            }
        }
        if(last == first){
            if(target == nums[first]){
                return true;
            }
        }
        return false;
    }
};

//解法二：采用二分排除法
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        if(len == 0){
            return false;
        }
        int left = 0;
        int right = len-1;
        
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] > target){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        if(nums[left] == target){
            return true;
        }
        return false;
    }
};
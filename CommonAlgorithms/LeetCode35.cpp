class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        int left = 0;
        int right = len-1;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] > target){
                right = mid-1;
            }else if(nums[mid] == target){
                return mid;
            }else{
                left = mid;
            }
        }
        if(nums[left] >= target){
            return left;
        }
        return left+1;
    }
};
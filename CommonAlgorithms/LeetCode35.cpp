/**
 * success Runtime: 4 ms, faster than 97.78% of C++ online submissions for Search Insert Position.
 * Memory Usage: 6.9 MB, less than 100.00% of C++ online submissions for Search Insert Position.
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int>::iterator it = find(nums.begin(), nums.end(), target);
        if(it != nums.end()){
            return &*it - &nums[0];
        }
        if(target < nums[0]){
            return 0;
        }
        if(target > nums[len-1]){
            return len;
        }
        int mid = (len-1)/2;
        while(1){
            if(target > nums[mid]){
                if (target < nums[mid+1])
                    return mid+1;
                else
                    mid = (mid + 1 + len-1)/2;
            }
            if(target < nums[mid]){
                if(target > nums[mid-1]){
                    return mid;
                }else
                    mid = (mid-1+0)/2;
            }
        
        }
    }
};
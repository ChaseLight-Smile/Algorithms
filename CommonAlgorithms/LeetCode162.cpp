//解法一: O(n) time complexity
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left = INT_MIN;
        int right = INT_MIN;
        int ans = -1;
        for(int i = 0; i < len; i++){
            if(i+1 < len-1){
                right = nums[i+1];
            }else
                right = INT_MIN;
            if(nums[i] >= left && nums[i] >= right){
                ans = i;
            }
            left = nums[i];
        }
        return ans;
    }
};
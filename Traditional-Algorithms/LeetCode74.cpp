class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool ans;
        if(matrix.size() == 0){
            return false;
        }
        for(auto n : matrix){
            ans = binarySearch(n, target);
            if(ans == true){
                ans = true;
                return true;
            }
        }
        return false;
    }
    bool binarySearch(vector<int>& nums, int target){
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
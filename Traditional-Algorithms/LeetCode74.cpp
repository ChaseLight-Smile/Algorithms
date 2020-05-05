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

//线性单调性二分
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return false;
        }
        int left = 0, right = matrix.size()* matrix[0].size()-1;
        while(left < right){
            int mid = left + right + 1 >> 1;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()] > target){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        if(matrix[left/matrix[0].size()][left%matrix[0].size()] == target){
            return true;
        }
        return false;
    }
};
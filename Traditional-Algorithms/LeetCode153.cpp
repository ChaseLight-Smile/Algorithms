class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0 ; 
        int right = len-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] > nums[right]){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return nums[left];
    }
};

//时间复杂度O(logn)，思路非常好
class Solution {
public:
    int findMin(vector<int>& nums) {
        int pivot = findPivot(nums);
        return nums[pivot];
    }
    int findPivot(vector<int>& nums){
        int len = nums.size();
        int left = 0 ;
        int right = len-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else if(nums[mid] > nums[right]){
                left = mid+1;
            }else if(nums[mid] == nums[right]){
                if(nums[right] == nums[right-1]){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return left;
    }
};




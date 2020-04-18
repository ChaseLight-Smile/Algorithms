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

//推荐这个理解思路
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
                //假如pivot在[mid+1,right]，假设mid+1就是pivot元素，那么一定存在nums[mid] > nums[pivot] > nums[right]，得到矛盾
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};



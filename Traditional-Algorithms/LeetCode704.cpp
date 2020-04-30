class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int first = 0;
        int last = len-1;
        int mid = 0;
        while(first < last){
            mid = (first + last)/2;
            if(target == nums[mid]){
                return mid;
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
                return first;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len-1;
        while(left < right){
            int mid = left + (right - left + 1)/2;
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
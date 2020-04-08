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
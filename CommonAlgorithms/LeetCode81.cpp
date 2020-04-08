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
class Solution {
public:
    int getNumberOfK(vector<int>& nums , int k) {
        if(nums.size() == 0){
            return 0;
        }
        int first = firstPosition(nums, k);
        int last = lastPosition(nums,k);
        if(first == -1 && last != -1){
            return 1;
        }
        if(first ==-1 && last == -1){
            return 0;
        }
        if(first != -1 && last == -1){
            return 1;
        }
        if(first != -1 && last != -1){
            return last - first +1;
        }
    }
    int firstPosition(vector<int>& nums, int k){
        int len = nums.size();
        if(len == 0){
            return -1;
        }
        int left = 0 ;
        int right = len-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] < k){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        if(nums[left] == k){
            return left;
        }
        return -1;
    }
    
    int lastPosition(vector<int>& nums, int k){
        int len = nums.size();
        if(len == 0){
            return -1;
        }
        int left = 0 ;
        int right = len-1;
        while(left < right){
            int mid = left + (right-left+1)/2;
            if(nums[mid] > k){
                right = mid-1;
            }else{
                left = mid;
            }
        }
        if(nums[left] == k){
            return left;
        }
        return -1;
    }
};
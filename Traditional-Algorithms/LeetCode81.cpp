//解法一：采用二分包含验证法 时间复杂度O(nlogn)
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

//解法二：采用二分排除法，时间复杂度O(nlogn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
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

//二分法，时间复杂度O(logn)
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //[3,3,3,5,3]  [3,1,1] [1,3,1,1] [1,1,3,1]中找3
        int len = nums.size();
        if(len == 0){
            return false;
        }
        int left = 0 ;
        int right = len-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else if(nums[mid] > nums[right]){
                left = mid+1;
            }else if(nums[mid] == nums[right]){
                if(nums[right] == nums[right-1])
                    right--;
                else{
                    left++;
                }
            }
        }
        int pivot = left;
        cout << pivot;
        left = 0; 
        right = pivot-1;
        int leftSide = binarySearch(nums,target,left,right);
        
        left = pivot; 
        right = len-1;
        int rightSide = binarySearch(nums,target,left,right);
        
        if(max(leftSide, rightSide) >= 0){
            return true;
        }else{
            return false;
        }
    }
    int binarySearch(vector<int>& nums, int target, int i , int j){
        int left = i;
        int right = j;
        while(left < right){
            int mid = left + (right-left+1)/2;
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
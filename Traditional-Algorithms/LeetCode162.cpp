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

//解法二： 实际上只需要比较单侧就可以，时间复杂度还是O(n)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        for(int i = 1 ; i < len; i++){
            if(nums[i] < nums[i-1]){
                return i-1;
            }
        }
        return len-1;
    }
};

//解法三： 二分查找
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left = 0 ;
        int right = len-1;
        int mid;
        while(left < right){
            mid = (left+right)/2;
            if(nums[mid] < nums[mid+1]) left = mid+1;
            else right = mid;
        }
        return right;
    }
};
//跟解法三一样的意思，只不过此时排除的是右边一侧
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int left = 0 ;
        int right = len-1;
        int mid;
        while(left < right){
            mid = left + (right - left + 1)/2;
            if(nums[mid] < nums[mid-1]) right = mid-1;
            else left = mid;
        }
        return left;
    }
};


//二分查找
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1){
            return 0;
        }
        
        int left = 0 ;
        int right = len-1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(mid-1>=0 && nums[mid] < nums[mid-1]){
                right = mid-1;
            }else if(mid+1<len && nums[mid] < nums[mid+1]){
                left = mid+1;
            }else{
                return mid;
            }
        }
        return left;
    }
};

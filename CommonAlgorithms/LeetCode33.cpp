class Solution {
public:
    int search(vector<int>& nums, int target) {
        map<int,int>m;
        int len = nums.size() ;
        for(int i = 0 ; i < len; i++){
            m[nums[i]] = i;
        }
        
        if(m.find(target) != m.end()){
            return m[target];
        }
        return -1;
    }
};


//方法二：时间复杂度O(logn) 空间复杂度O(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);
        int left = 0;
        int len = nums.size();
        if(len == 0){
            return -1;
        }
        int right = len-1;
        if(target == nums[pivot]){
            return pivot;
        }
        left = 0;
        right = pivot-1;
        int leftSide = binarySearch(nums,target,left,right);

        left = pivot; 
        right = len-1;
        int rightSide = binarySearch(nums,target,left,right);
        return max(leftSide, rightSide); 
    }
    int findPivot(vector<int>& nums){
        int len = nums.size() ; 
        int left = 0;
        int right = len-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else if(nums[mid] > nums[right]){
                left = mid+1;
            }else if(nums[mid] == nums[right]){
                //在数组中有重复时候的处理办法
                if(nums[right] == nums[right-1]){
                    right--;
                }else{
                    left++;
                }
            }
        }
        return left;
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
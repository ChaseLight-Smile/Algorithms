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

//解法二：O(3logn)
class Solution {
public:
    //O(3logn)
    int search(vector<int>& nums, int target) {
        int pivot = findPivot(nums);  //logn
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
        int rightSide = binarySearch(nums,target,left,right); //logn
       
        left = pivot; 
        right = len-1;
        int leftSide = binarySearch(nums,target,left,right);  //logn
        
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
            }else{
                left = mid+1;
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

//解法三：O(2logn)
class Solution {
public:
    //O(3logn)  [1,3]  [4,5,6,7,0,1,2]
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
        
        if(pivot == 0){
            left = pivot; 
            right = len-1;
            int leftSide = binarySearch(nums,target,left,right);
            return leftSide;
        }else if(target >= nums[left]){
            left = 0;
            right = pivot-1;
            int rightSide = binarySearch(nums,target,left,right);
            return rightSide;
        }else{
            left = pivot; 
            right = len-1;
            int leftSide = binarySearch(nums,target,left,right);
            return leftSide;
        }
    }
    int findPivot(vector<int>& nums){
        int len = nums.size() ; 
        int left = 0;
        int right = len-1;
        while(left < right){
            int mid = left + (right-left)/2;
            if(nums[mid] < nums[right]){
                right = mid;
            }else{
                left = mid+1;
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
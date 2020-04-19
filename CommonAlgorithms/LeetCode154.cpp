//时空复杂度为O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        priority_queue<int, vector<int>, greater<int>> q;
        for(int i = 0; i < len; i++){
            q.push(nums[i]);
        }
        return q.top();  
    }
};

//二分解法，时间复杂度O(logn)，空间复杂度O(1)
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
            }else if (nums[mid] > nums[right]){
                left = mid+1;
            }else if(nums[mid] == nums[right]){
                //[3,3,5,3]
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
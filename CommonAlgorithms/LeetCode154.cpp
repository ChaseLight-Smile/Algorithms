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

//二分解法，但是由于重复元素的存在，导致出现了破坏单调性的情况，应该特殊处理
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
                //说明右边一定有有序
                right = mid;
            }else if (nums[mid] > nums[right]){
                left = mid+1;
            }else if(nums[mid] == nums[right]){
                //如果相等，表明这个位置破坏了原来数据的单调性，应该特殊处理
                right--;
            }
                
        }
        return left;
    }
};
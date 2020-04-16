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
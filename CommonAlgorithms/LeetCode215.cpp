class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>> q;
        int len = nums.size();
        for(int i = 0 ; i < len; i++){
            q.push(nums[i]);
        }
        int ans;
        while(k > 0){
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};
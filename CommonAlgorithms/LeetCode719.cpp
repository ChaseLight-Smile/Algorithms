class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> ans;
        for(int i = 0 ; i < len-1; ++i){
            int left = i + 1;
            while(left < len){
                int tmp = abs(nums[left]-nums[i]);
                ans.push_back(tmp);
                ++left;
            }
        }
        sort(ans.begin(), ans.end());
        return ans[k-1];
    }
};
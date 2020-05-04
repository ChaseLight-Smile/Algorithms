class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        while(true){
            ans.push_back(nums);
            int i = nums.size()-1;
            while(i > 0 && nums[i-1] >= nums[i]){
                --i;
            }
            if(i == 0){
                break;
            }
            int j = nums.size()-1;
            while(j > i-1 && nums[j] <= nums[i-1]){
                --j;
            }
            swap(nums[i-1], nums[j]);
            reverse(nums.begin()+i, nums.end());
        }
        return ans;
    }
};
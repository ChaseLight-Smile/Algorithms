class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int len = nums.size();
        int i = 0;
        while(i < len){
            int j = nums[i];
            if(j <= len && nums[i] != nums[j-1]){
                swap(nums[i], nums[j-1]);
            }else{
                ++i;
            }
        }
        for(int i = 0; i < len; i++){
            if(nums[i] != i+1){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
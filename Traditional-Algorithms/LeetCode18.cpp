class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len-3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < len-2; j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int low = j + 1;
                int high = len-1;
                int sum = target - nums[i] -nums[j];
                while(low < high){
                    if(nums[low] + nums[high] == sum){
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        low++;
                        high--;
                    }else if (nums[low] + nums[high] > sum){
                        high--;
                    }else{
                        low++;
                    }
                }
                
            }
        }
        return ans;
    }
};
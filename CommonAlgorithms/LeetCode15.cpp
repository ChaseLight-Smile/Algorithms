class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len = nums.size();
        vector<vector<int>> ans;
        for(int i = 0 ; i < len-2;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
			int low = i +1;
			int high = len-1;
			int sum = 0-nums[i];
			while(low < high){
				if(nums[low] + nums[high] == sum){
					ans.push_back({nums[i], nums[low], nums[high]});
					while(low<high && nums[low] == nums[low+1]) low++;
					while(low<high && nums[high] == nums[high-1]) high--;
					low++;
					high--;
				}else if(nums[low] + nums[high] > sum){
					high--;
				}else{
					low++;
				}
			}
            
        }
        return ans;
    }
};
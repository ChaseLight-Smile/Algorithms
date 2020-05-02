class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        if(len == 0){
            return 0;
        }
        
        vector<int> maxArray(len);
        vector<int> minArray(len);
        int ans = INT_MIN;
        for(int i = 0; i < len; ++i){
            maxArray[i] = nums[i];
            if(i > 0){
                maxArray[i] = max(nums[i], max(nums[i]*maxArray[i-1], nums[i]*minArray[i-1]));
            }
            
            minArray[i] = nums[i];
            if(i > 0){
                minArray[i] = min(nums[i], min(nums[i]*maxArray[i-1], nums[i]*minArray[i-1]));
            }
            ans = max(ans, maxArray[i]);
        }
        return ans;
    } 
};
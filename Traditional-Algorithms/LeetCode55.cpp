//Dynamic Programming TLE
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        vector<bool>dp(len);
        int i, j;
        dp[0] = true;
        for(i = 1; i < len; i++){
            dp[i] = false;
            for(j = 0; j < i; j++){
               if(dp[j] && j+nums[j] >= i){
                   dp[i] = true;
				   break;
               }
           }
        }
        return dp[len-1];
    }
};
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int len = coins.size();
        //dp[0], dp[1], dp[amount]
        vector<int>dp(amount+1);
        dp[0] = 0;
        int i, j;
        for(int i = 1; i <= amount; i++){
            dp[i] = INT_MAX;
            for(int j = 0; j < len; j++){
                if(i >= coins[j] && dp[i-coins[j]] != INT_MAX){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
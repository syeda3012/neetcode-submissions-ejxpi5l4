class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for(int x = 1; x <= amount; x++){
            for(int coin : coins){
                if(coin <= x && dp[x - coin] != INT_MAX){
                    dp[x] = min(dp[x], dp[x - coin] + 1);
                }
            }
        }
      
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};

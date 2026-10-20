class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int i = 0; i <= n; i++){
             total += i;
        }
        if(total % 2 != 0)return false;

        int target = total / 2;

        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for(int i = 0; i <= n; i++){
            for(int j = target; j >= i; j--){
                dp[j] = dp[j] || dp[j-i];
            }
        }
        return dp[target];
    }
};

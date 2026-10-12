class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        int result1 = robLinear(nums, 1, n - 1);
        int result2 = robLinear(nums, 0, n - 2);
        return max(result1, result2);
    }
    int robLinear(vector<int>&nums, int start, int end){
        if(start == end){
            return nums[start];
        }
    vector<int>dp(nums.size());
    dp[start] = nums[start];
    dp[start + 1] = max(nums[start], nums[start + 1]);
    for(int i = start + 2; i <= end; i++){
        dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    }
    return dp[end];
    }
   
};

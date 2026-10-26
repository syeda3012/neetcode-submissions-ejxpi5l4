class Solution {
public:
    unordered_map<int, unordered_map<int, int>> memo;
    int solve(int index, int currentsum, vector<int>&nums, int target){
       
        if(index == nums.size()){

            if(target == currentsum)return 1;

            else{
                return 0;
            }
        }
        if(memo[index].find(currentsum) != memo[index].end()){
            return memo[index][currentsum];
        }
        
        int ways = solve(index + 1, currentsum + nums[index], nums, target) + solve(index + 1, currentsum - nums[index], nums, target);
        memo[index][currentsum] = ways;
        return ways;
    }
             
   
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int index = 0;
        int currentsum = 0;
        return solve(index, currentsum, nums, target);

    }
};

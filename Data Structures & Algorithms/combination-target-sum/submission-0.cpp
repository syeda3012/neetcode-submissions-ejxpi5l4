class Solution {
public:
    void getallcombinations(vector<int>& nums, int index, int target,
                           vector<vector<int>>& ans, vector<int>& combin) {
        
        // ✅ base case: valid combination
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        // ❌ stop conditions
        if (target < 0 || index == nums.size()) {
            return;
        }

        // ✅ PICK (stay at same index)
        combin.push_back(nums[index]);
        getallcombinations(nums, index, target - nums[index], ans, combin);

        // backtrack
        combin.pop_back();

        // ✅ NOT PICK (move to next index)
        getallcombinations(nums, index + 1, target, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        getallcombinations(nums, 0, target, ans, combin);
        return ans;
    }
};
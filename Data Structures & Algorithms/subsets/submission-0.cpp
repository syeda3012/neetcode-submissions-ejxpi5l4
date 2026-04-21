class Solution {
public:
    void getallsubsets(vector<int>& nums, int i, vector<int>& ans, vector<vector<int>>& allsubsets) {
        // Base case
        if (i == nums.size()) {
            allsubsets.push_back(ans);
            return;
        }

        // Pick the element
        ans.push_back(nums[i]);
        getallsubsets(nums, i + 1, ans, allsubsets);

        // Backtrack (remove element)
        ans.pop_back();

        // Not pick the element
        getallsubsets(nums, i + 1, ans, allsubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allsubsets;
        vector<int> ans;

        getallsubsets(nums, 0, ans, allsubsets);

        return allsubsets;
    }
};
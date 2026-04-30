class Solution {
public:
    void findSubsets(vector<int>nums, int index, vector<int>&ans, vector<vector<int>>&allsubsets){
        
            allsubsets.push_back(ans);
            
        
        for(int i = index; i < nums.size(); i++){
            if(i > index && nums[i] == nums[i-1])continue;

            ans.push_back(nums[i]);

            findSubsets(nums, i + 1, ans, allsubsets);

            ans.pop_back();

        
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>allsubsets;
        vector<int>ans;
        sort(nums.begin(), nums.end());
        findSubsets(nums, 0, ans, allsubsets);

        return allsubsets;
    }
};

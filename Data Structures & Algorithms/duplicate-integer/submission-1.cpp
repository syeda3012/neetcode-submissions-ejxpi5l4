class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>seen;
        for(int i = 0; i < n; i++){
            if(seen.count(nums[i])){
                return true;
            }
            seen.insert(nums[i]);
        }
        return false;
    }
};
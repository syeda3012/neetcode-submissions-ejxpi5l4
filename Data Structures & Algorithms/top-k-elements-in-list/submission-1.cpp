class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
          for(int num :nums){
            freq[num]++;
          }
          int n = nums.size();
          vector<vector<int>>bucket(n+1);
          for(auto&p : freq){
            bucket[p.second].push_back(p.first);
          }
          vector<int>result;
          for(int i = n; i >= 1  && result.size() < k; i--){
            for(int num: bucket[i]){
            result.push_back(num);
            if(result.size()==k)
            return result;
            }
          }
          return result; 
         }                                
};

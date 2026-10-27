class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        
        if(m + n != s3.length())return false;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
    
    private:
    bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>> &dp){
        bool ans = false;

        if(i == s1.length() && j == s2.length())return true;

        
        if(dp[i][j] != -1) return ans;

        if(i < s1.length()){
            if(s1[i] == s3[ i + j]){
                ans = ans|| solve(i + 1, j, s1, s2, s3, dp);
            }
        }
        if(j < s2.length()){
            if(s2[j] == s3[i + j]){
                ans = ans|| solve(i, j + 1, s1, s2, s3, dp);
            }
        }
        return dp[i][j] = ans;
        
    }
};

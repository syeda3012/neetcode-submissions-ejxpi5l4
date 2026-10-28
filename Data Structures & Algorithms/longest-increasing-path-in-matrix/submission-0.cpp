class Solution {
public:
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
       if(dp[i][j] != -1)return dp[i][j];

       int ans = 1;
       int dr[] = {1, -1, 0, 0};
       int dc[] = {0, 0, 1, -1};

       for(int k = 0; k < 4; k++){

        int ni = i + dr[k];
        int nj = j + dc[k];

        if(ni >= 0 && ni < matrix.size() && nj >=0 && nj < matrix[0].size()){

            if(matrix[ni][nj] > matrix[i][j]){

                ans = max(ans, 1 + dfs(ni, nj, matrix, dp));
            }
        }
       }
         dp[i][j] = ans;
         return dp[i][j];
    }

    
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();


        vector<vector<int>>dp(m, vector<int>(n, -1));

        int result = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                 
                 result = max(result, dfs(i, j, matrix, dp));
            }
        }
        return result;
    }
};

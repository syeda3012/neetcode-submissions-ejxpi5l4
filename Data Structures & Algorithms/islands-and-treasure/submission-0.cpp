class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };
        while(!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int newrow  = row + directions[k].first;
                int newcol = col + directions[k].second;

                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m &&
                grid[newrow][newcol] == 2147483647){
                    grid[newrow][newcol] = grid[row][col] + 1;
                    q.push({newrow, newcol});
                }
            }
        }

    }
};

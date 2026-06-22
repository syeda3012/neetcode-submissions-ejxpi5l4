class Solution {
public:
    int countIslands(vector<vector<int>> &grid, int i, int j, int n, int m){
        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0){
            return 0;
        }

        grid[i][j] = 0;
        int area = 1;

        area += countIslands(grid, i-1, j, n, m);
        area += countIslands(grid, i, j+1, n, m);
        area += countIslands(grid, i+1, j, n, m);
        area += countIslands(grid, i, j-1, n, m);

        return area;
        

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int Max = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
            
                if(grid[i][j] == 1){
                    int area = countIslands(grid, i, j, n, m);
                    Max = max(Max, area);
                }
            }
        }
        return Max;
        
        
    }
};

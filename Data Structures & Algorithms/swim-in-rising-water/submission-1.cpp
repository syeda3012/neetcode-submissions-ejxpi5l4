class Solution {
public: 
    int n;
    bool dfs(vector<vector<int>> &grid, int r, int c, int water, vector<vector<bool>> &visited){
        if(r < 0 || r >= n|| c < 0|| c >= n){
            return false;
        }
        if(visited[r][c])return false;
        if(grid[r][c] > water)return false;
        if(r == n -1 && c == n - 1)return true;
        visited[r][c] = true;
        if(dfs(grid, r + 1, c, water, visited))return true;
        if(dfs(grid, r - 1, c, water, visited))return true;
        if(dfs(grid, r, c + 1, water, visited))return true;
        if(dfs(grid, r, c - 1, water, visited))return true;
       return false;
    }
    bool canReach(vector<vector<int>> &grid, int water){
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        return dfs(grid, 0, 0, water, visited);
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int low = 0;
        int high = n * n - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(canReach(grid, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};

class Solution {
public:
    void bfs(queue<pair<int,int>>& q,
             vector<vector<bool>>& vis,
             vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        int dir[4][2] = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        while(!q.empty()) {
            pair<int,int> node = q.front();
            q.pop();

            int r = node.first;
            int c = node.second;

            for(int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   !vis[nr][nc] &&
                   heights[nr][nc] >= heights[r][c]) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        queue<pair<int,int>> pq, aq;

        // Pacific: left column
        for(int i = 0; i < n; i++) {
            pq.push({i, 0});
            pac[i][0] = true;
        }

        // Pacific: top row
        for(int j = 0; j < m; j++) {
            pq.push({0, j});
            pac[0][j] = true;
        }

        // Atlantic: right column
        for(int i = 0; i < n; i++) {
            aq.push({i, m - 1});
            atl[i][m - 1] = true;
        }

        // Atlantic: bottom row
        for(int j = 0; j < m; j++) {
            aq.push({n - 1, j});
            atl[n - 1][j] = true;
        }

        bfs(pq, pac, heights);
        bfs(aq, atl, heights);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
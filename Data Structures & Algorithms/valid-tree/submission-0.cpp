class Solution {
public:
   bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis){
              vis[node] = true;

              for(int i = 0; i < adj[node].size(); i++){
                int neighbour = adj[node][i];

                if(!vis[neighbour]){// if not visited and checking in deeper to find if theres a cycle
                    if(!dfs(neighbour, node, adj, vis)){
                        return false;
                    }
                }
                else if(neighbour != parent){// if visited but cycle found
                    return false;
                }
              }
              return true;
   }





    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1){
            return false;
        }
        vector<vector<int>> adj(n);
        for(int i = 0; i < edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
            vector<bool> vis(n, false);

             if(!dfs(0, -1, adj, vis)){
                return false;
             }
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    return false;
                }
            }
        

        return true;

    }
};

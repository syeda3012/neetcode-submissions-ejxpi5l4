class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(int i = 0; i < times.size(); i++){
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            adj[u].push_back({v,t});
        }
        vector<int>dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(d > dist[u]){/// if the previous distance value is greater than the current ignore it 
                continue;
            }
            // checking all the neighbors of the source node 
            for(int i = 0; i < adj[u].size(); i++){
                int v = adj[u][i].first;
                int w = adj[u][i].second;
            
                if(d + w < dist[v] ){
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == INT_MAX){
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
        
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<pair<int, int>> graph[n];

        // Build adjacency list
        for (int i = 0; i < flights.size(); i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];

            graph[u].push_back({v, wt});
        }

        // {airport, {cost, stops}}
        queue<pair<int, pair<int, int>>> q;

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // src, cost = 0, stops = -1
        q.push({src, {0, -1}});

        while (!q.empty()) {

            auto val = q.front();
            q.pop();

            int u = val.first;
            int cost = val.second.first;
            int stops = val.second.second;

            for (auto edge : graph[u]) {

                int v = edge.first;
                int wt = edge.second;

                // We can take another flight only if
                // the resulting number of stops is <= k
                if (stops + 1 <= k) {

                    int newCost = cost + wt;

                    if (newCost < dist[v]) {
                        dist[v] = newCost;

                        q.push({v, {newCost, stops + 1}});
                    }
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};
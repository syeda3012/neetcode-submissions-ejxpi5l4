class Solution {
public:
   unordered_map<string, priority_queue<string, vector<string>,greater<string>>> adj;
   vector<string> result;

   void dfs(string airport){

    while(!adj[airport].empty()){

       string next = adj[airport].top();
       adj[airport].pop();

       dfs(next);
    }

    result.push_back(airport);

   }

          
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i = 0; i < tickets.size(); i++){
            string from = tickets[i][0];
            string to = tickets[i][1];
            adj[from].push(to);
        }
        dfs("JFK");

        reverse(result.begin(), result.end());
        return result ;
    }
};

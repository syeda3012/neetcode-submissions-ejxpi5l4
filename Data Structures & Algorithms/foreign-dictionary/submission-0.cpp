class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<unordered_set<int>> graph(26);
        vector<int>indegree(26, 0);
        vector<int>present(26, false);
        int uniqueC = 0;
        for(string&word: words){
            for(char ch: word){
                int idx = ch-'a';
                if(!present[idx]){
                    present[idx] = true;
                    uniqueC++;
                }
            }
        }
        for(int i = 0; i < words.size()-1; i++){
            string &word1 = words[i];
            string &word2 = words[i+1];
            int len = min(word1.size(), word2.size());
            bool founddiff = false;
            for(int j = 0; j < len; j++){
                if(word1[j] != word2[j]){
                int u = word1[j] - 'a';
                int v = word2[j]- 'a';
                if(graph[u].insert(v).second){
                    indegree[v]++;
                }
                founddiff = true;
                break;
            }
            
        }
        if(!founddiff && word1.size() > word2.size()){
            return "";

        }
    } 
    queue<int>q;
    for(int i = 0; i <26; i++){
        if(present[i] && indegree[i] == 0){
            q.push(i);
        }
    }
       string result;
       while(!q.empty()){
        int u = q.front();
        q.pop();
        result += char(u + 'a');
        for(int v : graph[u]){
            indegree[v]--;
            if(indegree[v] == 0){
                q.push(v);
            }
          }
        } 
        if(result.size() != uniqueC){
            return "";
        }
        return result;
    }
};

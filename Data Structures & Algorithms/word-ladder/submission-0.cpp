class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool found = false;
        for(int i = 0; i < wordList.size(); i++){
            if(wordList[i] == endWord){
                found = true;
            }
        }
        if(!found) return 0;

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);
        int count = 1;

        while(!q.empty()){
            int size = q.size();
            for(int j = 0; j < size; j++){
                string current = q.front();
                q.pop();
                if(current == endWord){
                     return count;
                }
                for(int k = 0; k < wordList.size(); k++){
                    int diff = 0;
                    for(int i = 0; i < current.length(); i++){
                        if(current[i] != wordList[k][i]){
                            diff++;
                        }
                    }
                if(diff == 1 && visited.find(wordList[k]) == visited.end()){q.push(wordList[k]);
                visited.insert(wordList[k]);
                        }
                    
                }
    
            }count++;

        }return 0;
    }
};

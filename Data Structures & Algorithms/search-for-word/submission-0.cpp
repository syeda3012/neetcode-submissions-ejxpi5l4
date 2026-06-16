class Solution {
public:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k ){
        ///base case
        if(k == word.size()){
            return true;
        }
        ///impossibility 
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[k]){
            return false;
        }
        /// temporarily storing the value
        char temp = board[i][j];

        //marking it visited 
        board[i][j] = '#';

       ///directions of traversing the word
        bool found = dfs(board, word, i-1, j, k + 1)||
                     dfs(board, word, i+1, j, k + 1)||
                     dfs(board, word, i, j-1, k + 1)||
                     dfs(board, word, i, j+1, k + 1);

        // restoring the value before returning for future word framing
        board[i][j] = temp;
        return found;
    }


    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
        
    }

    
};

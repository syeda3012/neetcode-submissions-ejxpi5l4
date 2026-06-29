class Solution {
public:
    void DFS(vector<vector<char>>& board, int i, int j) {
        int rows = board.size();
        int cols = board[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cols || board[i][j] != 'O') {
            return;
        }

        board[i][j] = '*';

        DFS(board, i + 1, j);
        DFS(board, i - 1, j);
        DFS(board, i, j + 1);
        DFS(board, i, j - 1);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) {
            return;
        }

        int rows = board.size();
        int cols = board[0].size();

        // Traverse first and last row
        for (int j = 0; j < cols; j++) {
            if (board[0][j] == 'O') {
                DFS(board, 0, j);
            }

            if (board[rows - 1][j] == 'O') {
                DFS(board, rows - 1, j);
            }
        }

        // Traverse first and last column
        for (int i = 0; i < rows; i++) {
            if (board[i][0] == 'O') {
                DFS(board, i, 0);
            }

            if (board[i][cols - 1] == 'O') {
                DFS(board, i, cols - 1);
            }
        }

        // Convert surrounded regions and restore safe regions
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '*') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
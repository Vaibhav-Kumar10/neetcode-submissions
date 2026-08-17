class Solution {
public:
    void markUnSurroundableUsingDFS(int row, int col, vector<vector<char>>& board, 
            vector<vector<bool>>& unsurroundable, int n, int m) {
        if(row < 0 || col < 0 || row >= n || col >= m ||
            board[row][col] == 'X' || unsurroundable[row][col]) {
            return;
        }
        unsurroundable[row][col] = true;
        // Up
        markUnSurroundableUsingDFS(row - 1, col, board, unsurroundable, n, m);
        // Down
        markUnSurroundableUsingDFS(row + 1, col, board, unsurroundable, n, m);
        // Left
        markUnSurroundableUsingDFS(row, col - 1, board, unsurroundable, n, m);
        // Right
        markUnSurroundableUsingDFS(row, col + 1, board, unsurroundable, n, m);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> unsurroundable(n, vector<bool>(m, false));
        // Mark all border 'O' as non-surroundable
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && !unsurroundable[i][0]) {
                markUnSurroundableUsingDFS(i, 0, board, unsurroundable, n, m);
            }
        }
        for(int i = 0; i < n; i++) {
            if(board[i][m - 1] == 'O' && !unsurroundable[i][m - 1]) {
                markUnSurroundableUsingDFS(i, m - 1, board, unsurroundable, n, m);
            }
        }
        for(int j = 0; j < m; j++) {
            if(board[0][j] == 'O' && !unsurroundable[0][j]) {
                markUnSurroundableUsingDFS(0, j, board, unsurroundable, n, m);
            }
        }
        for(int j = 0; j < m; j++) {
            if(board[n - 1][j] == 'O' && !unsurroundable[n - 1][j]) {
                markUnSurroundableUsingDFS(n - 1, j, board, unsurroundable, n, m);
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !unsurroundable[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};

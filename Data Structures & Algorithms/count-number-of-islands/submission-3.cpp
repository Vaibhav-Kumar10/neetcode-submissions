class Solution {
   public:
    void markDFS(int row, int col, vector<vector<char>>& grid, int n, int m) {
        if (row < 0 || row >= n || col < 0 || col >= m || grid[row][col] == '0') {
            return;
        }

        grid[row][col] = '0';
        // Top
        markDFS(row - 1, col, grid, n, m);

        // Down
        markDFS(row + 1, col, grid, n, m);
        
        // Left
        markDFS(row, col - 1, grid, n, m);

        // Right
        markDFS(row, col + 1, grid, n, m);    
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                islands++;
                markDFS(i, j, grid, n, m);
            }
        }
        return islands;
    }
};

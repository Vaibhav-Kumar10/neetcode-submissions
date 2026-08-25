class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if (nr < 0 || nc < 0 || nr >= n || nc >= m ||
                    // skip already treasure chest, or water cells
                    grid[nr][nc] != 2147483647) {
                    continue;
                }
                grid[nr][nc] = grid[row][col] + 1;
                q.push({nr, nc});
            }
        }
    }
};

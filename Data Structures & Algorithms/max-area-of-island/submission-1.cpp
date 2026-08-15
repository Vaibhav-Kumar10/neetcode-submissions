class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0, n = grid.size(), m = grid[0].size();
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    int curArea = 1;
                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            int nr = row + dr[k], nc = col + dc[k];
                            if (nr >= 0 && nc >= 0 && nr < n && nc < m && 
                                    !visited[nr][nc] && grid[nr][nc] == 1) {
                                q.push({nr, nc});
                                visited[nr][nc] = true;
                                curArea++;
                            }
                        }
                    }
                    maxArea = max(maxArea, curArea);
                } else {
                    visited[i][j] = true;
                }
            }
        }
        return maxArea;
    }
};

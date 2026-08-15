class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), minutes = 0, fresh_cnt = 0;
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    fresh_cnt++;
                }
                else if(grid[i][j] == 2)  {
                    q.push({i, j});
                }
            }
        }
        while(!q.empty()) {
            int q_size = q.size();
            while(q_size--) {
                auto [row, col] = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nr = row + dr[i], nc = col + dc[i];
                    if(nr < 0 || nc < 0 || nr >= n || nc >= m ||
                        grid[nr][nc] == 0 || grid[nr][nc] == 2) {
                        continue;
                    }
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                    fresh_cnt--;
                }
            }
            if(!q.empty()) {
                minutes++;
            }
        }
        return fresh_cnt == 0 ? minutes : -1;
    }
};

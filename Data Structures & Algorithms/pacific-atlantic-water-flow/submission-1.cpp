class Solution {
public:
    void markVisitedUsingBFS(int x, int y, vector<vector<int>>& grid, 
            vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({x, y});
        int n = grid.size(), m = grid[0].size();
        vector<int> dr = {0, 1, 0, -1}, dc = {1, 0, -1, 0};
        visited[x][y] = true;
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nr = row + dr[i], nc = col + dc[i];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m || 
                        visited[nr][nc] || grid[nr][nc] < grid[row][col]) {
                    continue;
                }
                q.push({nr, nc});
                visited[nr][nc] = true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<bool>> pacific2node(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic2node(n, vector<bool>(m, false));
        // Mark all cells visitable from Pacific Ocean
        // First Column
        for(int i = 0; i < n; i++) {
            if(!pacific2node[i][0]) {
                markVisitedUsingBFS(i, 0, heights, pacific2node);
            }
        }
        // First Row
        for(int j = 0; j < m; j++) {
            if(!pacific2node[0][j]) {
                markVisitedUsingBFS(0, j, heights, pacific2node);
            }
        }
        // Mark all cells visitable from Atlantic Ocean
        // Last Column
        for(int i = 0; i < n; i++) {
            if(!atlantic2node[i][m - 1]) {
                markVisitedUsingBFS(i, m - 1, heights, atlantic2node);
            }
        }
        // Last Row
        for(int j = 0; j < m; j++) {
            if(!atlantic2node[n - 1][j]) {
                markVisitedUsingBFS(n - 1, j, heights, atlantic2node);
            }
        }
        // All those that are visitable from both Pacific and Atlantic ocean
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(pacific2node[i][j] && atlantic2node[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

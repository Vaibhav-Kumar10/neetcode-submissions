class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        queue<pair<int, int>> q;
        q.push({0, -1});
        visited[0] = true;
        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            for(auto nbr : adj[node]) {
                if(visited[nbr] == false) {
                    q.push({nbr, node});
                    visited[nbr] = true;
                }
                // Cycle found
                else if(nbr != parent) {
                    return false;
                }
            }
        }
        // Only 1 component, with all nodes connected
        for(int node = 0; node < n; node++) {
            if(!visited[node]) {
                return false;
            }
        }
        return true;
    }
};

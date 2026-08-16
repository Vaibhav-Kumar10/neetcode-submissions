class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                continue;
            }
            components++;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                auto node = q.front();
                q.pop();
                for(auto nbr : adj[node]) {
                    if(visited[nbr] == false) {
                        q.push(nbr);
                        visited[nbr] = true;
                    }
                }
            }
        }
        return components;
    }
};

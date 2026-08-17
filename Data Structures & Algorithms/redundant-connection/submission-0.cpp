class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        for(auto edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            indegree[a]++;
            indegree[b]++;
        }
        queue<int> q;
        for(int i = 1; i <= n; i++) {
            if(indegree[i] == 1) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            indegree[node]--;
            for(int nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 1) {
                    q.push(nbr);
                }
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            int a = edges[i][0], b = edges[i][1];
            if(indegree[a] > 0 && indegree[b] > 0) {
                return {a, b};
            }
        }
        return {};
    }
};

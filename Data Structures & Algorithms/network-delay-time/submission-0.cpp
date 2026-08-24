class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], t = edge[2];
            adj[u].push_back({v, t});
        }
        vector<int> time_taken(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // { cur_time, node }
        pq.push({0, k});
        time_taken[k] = 0;
        while (!pq.empty()) {
            auto [cur_time, node] = pq.top();
            pq.pop();
            if (cur_time > time_taken[node]) {
                continue;
            }
            for (auto [nbr_node, nbr_time] : adj[node]) {
                if (cur_time + nbr_time < time_taken[nbr_node]) {
                    time_taken[nbr_node] = cur_time + nbr_time;
                    pq.push({time_taken[nbr_node], nbr_node});
                }
            }
        }
        int min_reach_time = 0;
        for (int node = 1; node <= n; node++) {
            if (time_taken[node] == INT_MAX) {
                return -1;
            }
            min_reach_time = max(min_reach_time, time_taken[node]);
        }
        return min_reach_time;
    }
};
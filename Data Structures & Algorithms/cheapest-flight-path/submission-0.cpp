class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& flight_route : flights) {
            int from = flight_route[0], to = flight_route[1], price = flight_route[2];
            adj[from].push_back({to, price});
        }
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        pq.push({0, 0, src});
        while (!pq.empty()) {
            auto [stops, price, city] = pq.top();
            pq.pop();
            if (stops > k) {
                continue;
            }
            for (auto& [nbr_city, nbr_price] : adj[city]) {
                if (nbr_price + price < prices[nbr_city] && stops <= k) {
                    prices[nbr_city] = nbr_price + price;
                    pq.push({stops + 1, prices[nbr_city], nbr_city});
                }
            }
        }
        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};

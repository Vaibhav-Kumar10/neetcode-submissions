class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, minBuyingPrice = INT_MAX, n = prices.size();
        for(int i = 0; i < n; i++) {
            int curPrice = prices[i];
            minBuyingPrice = min(minBuyingPrice, curPrice);
            int curProfit = curPrice - minBuyingPrice; 
            maxProfit = max(maxProfit, curProfit);
        }
        return maxProfit;
    }
};

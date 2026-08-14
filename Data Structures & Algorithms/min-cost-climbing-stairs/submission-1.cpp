class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for(int ind = 2; ind <= n; ind++) {
            // 1 step
            int one_step = cost[ind - 1] + dp[ind - 1];
            // 2 step
            int two_step = cost[ind - 2] + dp[ind - 2];
            dp[ind] = min(one_step, two_step);
        }
        return dp[n];
    }
    /*
    int f(int ind, int n, vector<int>& cost, vector<int>& dp) {
        if(ind >= n) {
            return 0;
        }
        if(dp[ind] != -1) {
            return dp[ind];
        }
        // 1 step
        int one_step = cost[ind] + f(ind + 1, n, cost, dp);
        // 2 step
        int two_step = cost[ind] + f(ind + 2, n, cost, dp);
        return dp[ind] = min(one_step, two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(f(0, n, cost, dp), f(1, n, cost, dp));
    }
    */
};

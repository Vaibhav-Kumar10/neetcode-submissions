class Solution {
   public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for(int cur = 3; cur <= n; cur++) {
            // 1 step
            int one_step = dp[cur - 1];
            // 2 step
            int two_step = dp[cur - 2];
            dp[cur] = one_step + two_step;
        }
        return dp[n];
    }
    /*
    int f(int cur, int n, vector<int>& dp) {
        if (cur >= n) {
            return cur == n;
        }
        if (dp[cur] != -1) {
            return dp[cur];
        }
        // 1 step
        int one_step = f(cur + 1, n, dp);
        // 2 step
        int two_step = f(cur + 2, n, dp);
        return dp[cur] = one_step + two_step;
    }
    int climbStairs(int n) {
        int cur = 0;
        vector<int> dp(n + 1, -1);
        return f(cur, n, dp);
    }
    */
};

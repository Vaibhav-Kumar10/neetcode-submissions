class Solution {
public:
    int f(int cur, int n, vector<int>& dp) {
        if(cur == n) {
            return 1;
        }
        if(cur > n) {
            return 0;
        }
        if(dp[cur] != -1) {
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
};

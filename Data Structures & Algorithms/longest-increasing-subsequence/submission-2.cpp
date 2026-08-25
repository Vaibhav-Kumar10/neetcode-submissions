class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), maxLIS = 0;
        vector<int> dp(n, 1);
        for (int ind = 0; ind < n; ind++) {
            for (int prev = 0; prev < ind; prev++) {
                if (nums[prev] < nums[ind]) {
                    dp[ind] = max(dp[ind], 1 + dp[prev]);
                }
            }
            maxLIS = max(maxLIS, dp[ind]);
        }
        return maxLIS;
    }
    /*
    int lengthOfLIS(vector<int>& nums) {
        int ind = 0, prev = 0, n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int prev = ind - 1; prev >= -1; prev--) {
                int take_cur = INT_MIN;
                if ((prev == -1) || (nums[ind] > nums[prev])) {
                    take_cur = 1 + dp[ind + 1][ind + 1];
                }
                int skip_cur = dp[ind + 1][prev + 1];
                dp[ind][prev + 1] = max(take_cur, skip_cur);
            }
        }
        return dp[0][0];
    }
    */
    /*
    int f(int ind, int prev, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (ind == n) {
            return 0;
        }
        if (dp[ind][prev + 1] != -1) {
            return dp[ind][prev + 1];
        }
        int take_cur = INT_MIN;
        if ((prev == -1) || (nums[ind] > nums[prev])) {
            take_cur = 1 + f(ind + 1, ind, nums, n, dp);
        }
        int skip_cur = f(ind + 1, prev, nums, n, dp);
        return dp[ind][prev + 1] = max(take_cur, skip_cur);
    }
    int lengthOfLIS(vector<int>& nums) {
        int ind = 0, prev = -1, n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(ind, prev, nums, n, dp);
    }
    */
};

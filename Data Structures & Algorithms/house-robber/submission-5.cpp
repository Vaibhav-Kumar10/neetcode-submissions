class Solution {
   public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        int prev2 = nums[0], prev1 = max(nums[0], nums[1]);
        for (int ind = 2; ind < n; ind++) {
            // skip cur house
            int not_take = prev1;
            // rob cur house
            int take = nums[ind] + prev2;
            int curMax = max(take, not_take);
            prev2 = prev1;
            prev1 = curMax;
        }
        return prev1;
    }
    /*
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int ind = 2; ind < n; ind++) {
            // skip cur house
            int not_take = dp[ind - 1];
            // rob cur house
            int take = nums[ind] + dp[ind - 2];
            dp[ind] = max(take, not_take);
        }
        return dp[n - 1];
    }
    */
    /*
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2, 0);
        for (int ind = n - 1; ind >= 0; ind--) {
            // skip cur house
            int not_take = dp[ind + 1];
            // rob cur house
            int take = nums[ind] + dp[ind + 2];
            dp[ind] = max(take, not_take);
        }
        return dp[0];
    }
    */
    /*
    int f(int ind, vector<int>& nums, int n, vector<int>& dp) {
        if (ind >= n) {
            return 0;
        }
        if (dp[ind] != -1) {
            return dp[ind];
        }
        // skip cur house
        int not_take = f(ind + 1, nums, n, dp);
        // rob cur house
        int take = nums[ind] + f(ind + 2, nums, n, dp);
        return dp[ind] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        int ind = 0, n = nums.size();
        vector<int> dp(n + 1, -1);
        return f(ind, nums, n, dp);
    }
    */
};

class Solution {
   public:
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
};

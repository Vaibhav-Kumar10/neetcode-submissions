class Solution {
   public:
    bool f(int ind, int target, vector<int>& nums, int n, vector<vector<int>>& dp) {
        if (target == 0) {
            return true;
        }
        if (ind == n) {
            return target == 0;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        int take_cur = (nums[ind] <= target) ? f(ind + 1, target - nums[ind], nums, n, dp) : false;
        int skip_cur = f(ind + 1, target, nums, n, dp);
        return dp[ind][target] = take_cur || skip_cur;
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        // Odd total_sum => can't partition into equal sub sets
        if (total_sum & 1) {
            return false;
        }
        int target = total_sum / 2, ind = 0, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return f(ind, target, nums, n, dp);
    }
};

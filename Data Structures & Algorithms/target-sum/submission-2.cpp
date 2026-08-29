class Solution {
   public:
    vector<vector<int>> dp;
    int f(int ind, int target, vector<int>& nums, int n) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0) {
                return 2;
            }
            if (target == 0 || target == nums[0]) {
                return 1;
            }
            return 0;
        }
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        // take cur
        int take = nums[ind] <= target ? f(ind - 1, target - nums[ind], nums, n) : 0;
        // skip cur
        int skip = f(ind - 1, target, nums, n);
        return dp[ind][target] = take + skip;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        if ((total_sum < target) || (total_sum - target) % 2 == 1) {
            return 0;
        }
        int ind = nums.size() - 1, n = nums.size(), t = (total_sum - target) / 2;
        dp.assign(n, vector<int>(t + 1, -1));
        return f(ind, t, nums, n);
    }
};

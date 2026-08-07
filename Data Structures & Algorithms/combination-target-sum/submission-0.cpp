class Solution {
public:
    void f(int ind, int target, vector<int>& cur, vector<vector<int>>& ans, 
            vector<int>& nums, int n) {
        if(ind == n) {
            if(target == 0) {
                ans.push_back(cur);
            }
            return;
        }
        // Take current element and try itself again
        if(nums[ind] <= target) {
            cur.push_back(nums[ind]);
            f(ind, target - nums[ind], cur, ans, nums, n);
            cur.pop_back();
        }

        // Skip current element
        f(ind + 1, target, cur, ans, nums, n);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size(), ind = 0;
        f(ind, target, cur, ans, nums, n);
        return ans;
    }
};

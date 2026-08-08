class Solution {
   public:
    void f(int ind, int target, vector<int>& cur, vector<vector<int>>& ans, 
            vector<int>& nums, int n) {
        if (target == 0) {
            ans.push_back(cur);
            return;
        }
        if (ind == n) {
            return;
        }
        // Take cur element
        if (target >= nums[ind]) {
            cur.push_back(nums[ind]);
            f(ind + 1, target - nums[ind], cur, ans, nums, n);
            cur.pop_back();
        }

        // Skip cur element = nums[ind] and all its duplicates
        int nextIdx = ind + 1;
        while (nextIdx < n && nums[nextIdx] == nums[ind]) {
            nextIdx++;
        }
        f(nextIdx, target, cur, ans, nums, n);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> cur;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        int n = candidates.size(), ind = 0;
        f(ind, target, cur, ans, candidates, n);
        return ans;
    }
};

class Solution {
public:
    void f(int ind, vector<int>& cur, vector<vector<int>>& ans, 
            vector<int>& nums, int n) {
        if(ind == n) {
            ans.push_back(cur);
            return;
        }

        // take current element;
        cur.push_back(nums[ind]);
        f(ind + 1, cur, ans, nums, n);
        cur.pop_back();

        // Skip cur element = nums[ind] and all its duplicates
        int nextIdx = ind + 1;
        while (nextIdx < n && nums[nextIdx] == nums[ind]) {
            nextIdx++;
        }
        f(nextIdx, cur, ans, nums, n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size(), ind = 0;
        sort(nums.begin(), nums.end());
        f(ind, cur, ans, nums, n);
        return ans;
    }
};

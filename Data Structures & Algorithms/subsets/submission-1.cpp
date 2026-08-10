class Solution {
public:
    void f(int ind, vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums, int n) {
        // If all elements have been visited
        if(ind == n) {
            // Add cur subset to ans 
            ans.push_back(cur);
            return;
        }
        // Skip current element and try subset without that element
        f(ind + 1, cur, ans, nums, n);

        // Take current element and try next subset 
        cur.push_back(nums[ind]);
        f(ind + 1, cur, ans, nums, n);
        // Backtrack - remove the current element
        cur.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        int n = nums.size(), ind = 0;
        f(ind, cur, ans, nums, n);
        return ans;
    }
};

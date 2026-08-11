class Solution {
public:
    void f(int ind, vector<int>& nums, vector<vector<int>>& ans, int n) {
        if(ind == n) {
            ans.push_back(nums);
            return;
        }
        for(int i = ind; i < n; i++) {
            swap(nums[ind], nums[i]);
            f(ind + 1, nums, ans, n);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size(), ind = 0;
        f(ind, nums, ans, n);
        return ans;
    }
};

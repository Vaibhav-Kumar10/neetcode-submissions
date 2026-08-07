class Solution {
public:
    void f(int ind, vector<int>& cur, vector<vector<int>>& ans, 
            vector<int>& nums, set<vector<int>>& st) {
        if(ind == nums.size()) {
            if(st.find(cur) == st.end()) {
                ans.push_back(cur);
                st.insert(cur);
            }
            return;
        }
        // take
        cur.push_back(nums[ind]);
        f(ind + 1, cur, ans, nums, st);
        cur.pop_back();

        // not take
        f(ind + 1, cur, ans, nums, st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        vector<int> cur;
        f(0, cur, ans, nums, st);
        return ans;
    }
};

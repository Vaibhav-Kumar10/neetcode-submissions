class Solution {
public:
    void f(int num, vector<int>& cur, vector<vector<int>>& ans, int n, int k) {
        if(cur.size() == k) {
            ans.push_back(cur);
            return;
        }
        if(num > n) {
            return;
        }
        // Take cur num
        cur.push_back(num);
        f(num + 1, cur, ans, n, k);
        cur.pop_back();
        // Skip cur num
        f(num + 1, cur, ans, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        int num = 1;
        f(num, cur, ans, n, k);
        return ans;
    }
};
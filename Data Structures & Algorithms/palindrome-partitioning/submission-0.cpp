class Solution {
public:
    bool isPalindrome(string& s, int l, int r) {
        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void f(int ind, vector<string>& cur, vector<vector<string>>& ans, string& s, int n) {
        if(ind == n) {
            ans.push_back(cur);
            return;
        }
        for(int i = ind; i < n; i++) {
            if(isPalindrome(s, ind, i)) {
                cur.push_back(s.substr(ind, i - ind + 1));
                f(i + 1, cur, ans, s, n);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size(), ind = 0;
        vector<string> cur;
        vector<vector<string>> ans;
        f(ind, cur, ans, s, n);
        return ans;
    }
};

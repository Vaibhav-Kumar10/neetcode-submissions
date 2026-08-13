class Solution {
public:
    void f(int ind, string cur, vector<string>& ans, string& digits, int n, 
            unordered_map<int, string>& dig2char) {
        if(ind == n) {
            ans.push_back(cur);
            return;
        }
        int digit = digits[ind] - '0';
        for(char ch : dig2char[digit]) {
            f(ind + 1, cur + ch, ans, digits, n, dig2char);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur = "";
        unordered_map<int, string> dig2char = {
            {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, 
            {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
        };
        int n = digits.size(), ind = 0;
        if(n == 0) {
            return ans;
        }
        f(ind, cur, ans, digits, n, dig2char);
        return ans;
    }
};

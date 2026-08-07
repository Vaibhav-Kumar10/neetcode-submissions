class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size(), len2 = t.length();
        if(len1 != len2) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};

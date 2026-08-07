class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1 = s.size(), len2 = t.length();
        if(len1 != len2) {
            return false;
        }
        vector<int> freq1(26, 0), freq2(26, 0);
        for(char ch : s) {
            freq1[ch - 'a']++;
        }
        for(char ch : t) {
            freq2[ch - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) {
                return false;
            }
        }
        return true;
        /*
        int len1 = s.size(), len2 = t.length();
        if(len1 != len2) {
            return false;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        */
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s == t;
        if(s.size() != t.size()) {
            return false;
        }
        unordered_map<int, int> charFreq;
        for(int i = 0; i < s.size(); i++) {
            charFreq[s[i]]++;
            charFreq[t[i]]--;
        }
        for(auto it : charFreq) {
            if(it.second != 0) {
                return false;
            }
        }
        return true;
    }
};

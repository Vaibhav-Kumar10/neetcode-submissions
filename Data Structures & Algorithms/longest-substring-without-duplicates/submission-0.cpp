class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, n = s.size(), maxLen = 0;
        unordered_map<char, int> charFreq;
        for(r; r < n; r++) {
            charFreq[s[r]]++;
            while(l <= r && charFreq[s[r]] > 1) {
                charFreq[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        return maxLen;
    }
};

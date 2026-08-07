class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        vector<vector<string>> ans;
        for(string str : strs) {
            vector<int> charCount(26, 0);
            for(char ch : str) {
                charCount[ch - 'a']++;
            }
            string hashKey = to_string(charCount[0]);
            for(int i = 1; i < 26; i++) {
                hashKey += "," + to_string(charCount[i]);
            }
            anagramMap[hashKey].push_back(str);
        }
        for(auto it : anagramMap) {
            ans.push_back(it.second);
        }
        return ans;

        // vector<vector<string>> ans;
        // for(string str : strs) {
        //     unordered_map<char, int> freqs;
        //     for(char ch : str) {
        //         freqs[ch]++;
        //     }
        //     vector<string> a = {str};
        //     for(string s2 : strs) {
        //         unordered_map<char, int> freq = freqs;
        //         if(s2 != str) {
        //             for(char ch2 : s2) {
        //                 freq[ch2]--;
        //             }
        //         }
        //         bool isAnagram = true;
        //         for(auto it : freq) {
        //             if(it.second != 0) {
        //                 isAnagram = false;
        //                 break;
        //             }
        //         }
        //         if(isAnagram) {
        //             a.push_back(s2);
        //         }
        //     }
        //     ans.push_back(a);
        // }
        // return ans;
    }
};

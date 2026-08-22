class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int num : nums) {
            freqMap[num]++;
        }
        vector<int> ans;
        vector<pair<int, int>> arr;
        for(auto [num, freq] : freqMap) {
            arr.push_back({freq,num});
        }
        sort(arr.rbegin(), arr.rend());
        for(int i = 0; i < k; i++) {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};

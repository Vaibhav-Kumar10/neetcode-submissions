class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for(int num : nums) {
            freqMap[num]++;
        }
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(auto [num, freq] : freqMap) {
            pq.push({freq,num});
        }
        while(!pq.empty() && k > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
    /*
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
    */
};

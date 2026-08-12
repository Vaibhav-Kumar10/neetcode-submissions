class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        // Store elements with their respective indices
        priority_queue<pair<int, int>> maxHeap;
        for (int i = 0; i < k; i++) {
            maxHeap.push({nums[i], i});
        }
        ans.push_back(maxHeap.top().first);
        for (int i = k; i < n; i++) {
            maxHeap.push({nums[i], i});
            while (maxHeap.top().second <= i - k) {
                maxHeap.pop();
            }
            ans.push_back(maxHeap.top().first);
        }
        return ans;
    }
};

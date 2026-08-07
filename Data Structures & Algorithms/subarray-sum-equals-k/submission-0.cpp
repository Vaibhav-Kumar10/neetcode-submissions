class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap;
        int cnt = 0, curSum = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            curSum += nums[i];
            if(curSum == k) {
                cnt++;
            }
            if(sumMap.find(curSum - k) != sumMap.end()) {
                cnt += sumMap[curSum - k];
            }
            sumMap[curSum]++;
        }
        return cnt;
    }
};
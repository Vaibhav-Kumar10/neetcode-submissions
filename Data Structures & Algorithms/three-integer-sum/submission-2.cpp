class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            unordered_map<int, int> sumMap;
            for(int j = i + 1; j < n; j++) {
                int req = -(nums[i] + nums[j]);
                if(sumMap.find(req) != sumMap.end()) {
                    ans.push_back({nums[i], req, nums[j]});
                    while(j + 1 < n && nums[j] == nums[j + 1]) {
                        j++;
                    }
                }
                sumMap[nums[j]] = j;
            }
        }
        return ans;
    }
};

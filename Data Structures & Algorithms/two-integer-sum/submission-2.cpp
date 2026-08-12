class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int reqDif = target - nums[i];
            if(mapp.find(reqDif) != mapp.end()) {
                return {mapp[reqDif], i};
            }
            mapp[nums[i]] = i;
        }
        return {-1, -1};
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxRightReachable = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > maxRightReachable) {
                return false;
            }
            int curRightReachable = i + nums[i];
            maxRightReachable = max(maxRightReachable, curRightReachable);
            if(maxRightReachable >= n - 1) {
                return true;
            }
        }
        return maxRightReachable >= n - 1;
    }
};

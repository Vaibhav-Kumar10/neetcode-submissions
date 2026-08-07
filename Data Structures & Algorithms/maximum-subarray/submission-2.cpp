class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curSum = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(curSum < 0) {
                curSum = 0;
            }
            curSum += nums[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};

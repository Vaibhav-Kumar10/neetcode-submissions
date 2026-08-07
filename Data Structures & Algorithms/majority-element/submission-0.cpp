class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int candidate = nums[0];
        for(int i = 1; i < n; i++) {
            if(nums[i] == candidate) {
                cnt++;
            }
            else {
                if(cnt == 0) {
                    candidate = nums[i];
                }
                else {
                    cnt--;
                }
            }
        }
        return candidate;
    }
};
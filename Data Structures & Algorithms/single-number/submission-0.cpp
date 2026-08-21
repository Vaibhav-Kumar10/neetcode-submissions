class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cur_xor = 0;
        for(int num : nums) {
            cur_xor ^= num;
        }
        return cur_xor;
    }
};

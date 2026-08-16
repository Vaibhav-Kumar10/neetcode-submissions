class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cur_sum = 0, sub_arr_cnt = 0;
        unordered_map<int, int> prev_occ;
        prev_occ[0] = 1;
        for(int i = 0; i < n; i++) {
            cur_sum += nums[i];
            if(prev_occ.find(cur_sum - k) != prev_occ.end()) {
                sub_arr_cnt += prev_occ[cur_sum - k];
            }
            prev_occ[cur_sum]++;
        }
        return sub_arr_cnt;
    }
};
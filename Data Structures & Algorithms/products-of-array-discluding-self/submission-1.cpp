class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0), prefixProduct(n, 1), suffixProduct(n, 1);
        for (int i = 1; i < n; i++) {
            prefixProduct[i] = prefixProduct[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; i--) {
            suffixProduct[i] = suffixProduct[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = prefixProduct[i] * suffixProduct[i];
        }
        return ans;
    }
    /*
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), zero_cnt = 0, total_product = 1;
        vector<int> ans(n, 0);
        for (int num : nums) {
            if (num == 0) {
                zero_cnt++;
            } else {
                total_product *= num;
            }
        }
        if (zero_cnt > 1) {
            return ans;
        }
        for (int i = 0; i < n; i++) {
            if(zero_cnt > 0) {
                if(nums[i] == 0) {
                    ans[i] = total_product;
                }
                else {
                    ans[i] = 0;
                }
            }
            else {
                ans[i] = total_product / nums[i];
            }
        }
        return ans;
    }
    */
};

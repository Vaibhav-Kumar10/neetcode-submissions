class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_set<int> all_nums(nums.begin(), nums.end());
        int longest = 0;
        for (int num : all_nums) {
            // If previous no. is not present in the set.
            if (all_nums.find(num - 1) == all_nums.end()) {
                int x = num, cnt = 1;
                // Find the longest sequence in which next number is present
                while (all_nums.find(x + 1) != all_nums.end()) {
                    x++;
                    cnt++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

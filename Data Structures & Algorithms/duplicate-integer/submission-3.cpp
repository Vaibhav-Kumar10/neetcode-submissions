class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> occured;
        for(int el : nums) {
            occured.insert(el);
        }
        return occured.size() != nums.size();

        /*
        unordered_map<int, int> freqMap;
        for(int i = 0; i < nums.size(); i++) {
            freqMap[nums[i]]++;
            if(freqMap[nums[i]] > 1){ 
                return true;
            }
        }
        return false;
        */

        /*
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1]) {
                return true;
            }
        }
        return false;
        */
    }
};
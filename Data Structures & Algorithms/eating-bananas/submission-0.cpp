class Solution {
   public:
    int canEat(int k, vector<int>& piles, int h) {
        int hrs = 0;
        for (int banana : piles) {
            int cur_hr = (banana + k - 1) / k;
            hrs += cur_hr;
            if (hrs > h) {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0, high = *max_element(piles.begin(), piles.end());
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (canEat(mid, piles, h)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return high;
    }
};

class Solution {
   public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int low = 1, high = x;
        while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (1LL * mid * mid <= x) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return low;
    }
};
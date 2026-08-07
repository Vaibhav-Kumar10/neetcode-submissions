class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0, right = heights.size() - 1, maxCap = 0;
        while(left <= right) {
            int dif = right - left;
            int cap = dif * min(heights[left], heights[right]) ;
            maxCap = max(maxCap, cap);
            if(heights[left] < heights[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return maxCap;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int stone : stones) {
            maxHeap.push(stone);
        }
        while(maxHeap.size() > 1) {
            int a = maxHeap.top();
            maxHeap.pop();
            int b = maxHeap.top();
            maxHeap.pop();
            if(a > b) {
                maxHeap.push(a - b);
            }
        }
        maxHeap.push(0);
        return maxHeap.top();
    }
};

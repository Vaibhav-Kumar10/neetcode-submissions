class Solution {
   public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;
        for (string op : operations) {
            if (op == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b);
                ans += st.top();
            } else if (op == "D") {
                int num = st.top();
                st.push(num * 2);
                ans += st.top();
            } else if (op == "C") {
                ans -= st.top();
                st.pop();
            } else {
                st.push(stoi(op));
                ans += st.top();
            }
        }
        return ans;
    }
};
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusted_by(n + 1, 0);
        vector<int> trusts(n + 1, 0);
        for(vector<int> trust_from_to : trust) {
            int a = trust_from_to[0], b = trust_from_to[1];
            trusted_by[a]++;
            trusts[b]++;
        }
        int judge = -1;
        for(int i = 1; i <= n; i++) {
            if(trusted_by[i] == 0 && trusts[i] == n - 1) {
                if(judge == -1) {
                    judge = i;
                }
                else {
                    return -1;
                }
            }
        }
        return judge;
    }
};
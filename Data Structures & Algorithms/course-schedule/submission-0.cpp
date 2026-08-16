class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto prerequisite : prerequisites) {
            int a = prerequisite[0], b = prerequisite[1];
            adj[b].push_back(a);
            indegree[a]++;
        }
        queue<int> q;
        for(int course = 0; course < numCourses; course++) {
            if(indegree[course] == 0) {
                q.push(course);
            }
        }
        vector<int> topo;
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(int nbr : adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        return topo.size() == numCourses;
    }
};

class Solution {
   public:
    string topoSort(unordered_map<char, vector<char>>& adj, unordered_map<char, int> indegree) {
        string ans = "";
        queue<char> q;
        for (auto [ch, indgree] : indegree) {
            if (indgree == 0) {
                q.push(ch);
            }
        }
        while (!q.empty()) {
            auto ch_node = q.front();
            q.pop();
            ans += ch_node;
            for (auto nbr_ch : adj[ch_node]) {
                indegree[nbr_ch]--;
                if (indegree[nbr_ch] == 0) {
                    q.push(nbr_ch);
                }
            }
        }
        return ans;
    }
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        unordered_set<char> allChars;
        // Store all the chars present in all the words
        for (string word : words) {
            for (char ch : word) {
                allChars.insert(ch);
            }
        }
        // Adjacency Matrix
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        // Initialize the indegree for each char
        for (char ch : allChars) {
            indegree[ch] = 0;
        }
        // Take two words at a time, and compare them
        for (int i = 0; i < n - 1; i++) {
            string word1 = words[i], word2 = words[i + 1];
            int ptr = 0, n1 = word1.size(), n2 = word2.size();
            while (ptr < n1 && ptr < n2 && word1[ptr] == word2[ptr]) {
                ptr++;
            }
            // If longer word is present first => Invalid case
            if (ptr < n1 && ptr == n2) {
                return "";
            }
            // For different chars, store them in adjacency matrix
            if (ptr < n1 && ptr < n2) {
                char u = word1[ptr], v = word2[ptr];
                // u came before v
                adj[u].push_back(v);
                indegree[v]++;
            }
        }

        // Apply Toplogical Sort and find the dependencies
        string ans = topoSort(adj, indegree);
        // If cyclic dependency => Not possible
        if (ans.size() != allChars.size()) {
            return "";
        }
        return ans;
    }
};

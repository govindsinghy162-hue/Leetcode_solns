class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);

        // Original tree banana
        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> newParent(n);
        vector<int> ans(n, 1);

        for (int i = 0; i < n; i++) {
            newParent[i] = parent[i];
        }

        // Har character ke ancestors ki stack
        vector<int> st[26];

        // DFS: parent change find karna
        function<void(int)> dfs = [&](int node) {
            int c = s[node] - 'a';

            // Same character ka nearest ancestor
            if (!st[c].empty()) {
                newParent[node] = st[c].back();
            }

            st[c].push_back(node);

            for (int child : adj[node]) {
                dfs(child);
            }

            st[c].pop_back();
        };

        dfs(0);

        // New tree banana
        vector<vector<int>> tree(n);

        for (int i = 1; i < n; i++) {
            tree[newParent[i]].push_back(i);
        }

        // Subtree size calculate karna
        function<int(int)> calculate = [&](int node) {
            int size = 1;

            for (int child : tree[node]) {
                size += calculate(child);
            }

            ans[node] = size;
            return size;
        };

        calculate(0);

        return ans;
    }
};
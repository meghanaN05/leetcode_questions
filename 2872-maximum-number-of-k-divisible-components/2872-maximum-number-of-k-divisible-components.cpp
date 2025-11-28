class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int ans = 0;
        vector<int> vis(n, 0);
        function<long long(int)> dfs = [&](int u) {
            vis[u] = 1;
            long long sum = values[u];
            for (int v : adj[u]) {
                if (!vis[v]) {
                    long long childSum = dfs(v);
                    sum += childSum;
                }
            }
            if (sum % k == 0) {
                ans++;
                return 0LL; 
            }
            return sum; 
        };

        dfs(0);
        return ans;
    }
};

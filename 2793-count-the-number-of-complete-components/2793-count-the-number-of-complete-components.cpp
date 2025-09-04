class Solution {
public:
    void dfs(int curr, int &nodes, int &edges, vector<vector<int>>& adj, vector<int>& visited) {
        visited[curr] = 1;
        nodes++;
        for (int &it : adj[curr]) {
            edges++;
            if (!visited[it]) {
                dfs(it, nodes, edges, adj, visited);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int cnt = 0;
        vector<int> visited(n, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0, edgesCount = 0;
                dfs(i, nodes, edgesCount, adj, visited);
                if (edgesCount == nodes * (nodes - 1)) cnt++;
            }
        }

        return cnt;
    }
};

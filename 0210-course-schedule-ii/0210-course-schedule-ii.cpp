class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
        }
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int neigh : adj[i]) {
                indegree[neigh]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> ans;
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            cnt++;

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0)
                    q.push(neigh);
            }
        }
        reverse(ans.begin(),ans.end());
        if (cnt == V) return ans;  
        return {};                
    }
};

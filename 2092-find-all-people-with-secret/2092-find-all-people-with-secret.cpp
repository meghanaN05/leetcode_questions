class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<bool> secret(n, false);
        secret[0] = true;
        secret[firstPerson] = true;
        sort(meetings.begin(), meetings.end(),
             [](auto &a, auto &b) {
                 return a[2] < b[2];
             });

        int i = 0;
        while (i < meetings.size()) {
            int time = meetings[i][2];
            unordered_map<int, vector<int>> graph;
            queue<int> q;
            unordered_set<int> visited;
            while (i < meetings.size() && meetings[i][2] == time) {
                int x = meetings[i][0];
                int y = meetings[i][1];
                graph[x].push_back(y);
                graph[y].push_back(x);
                if (secret[x]) q.push(x);
                if (secret[y]) q.push(y);
                i++;
            }
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                if (visited.count(u)) continue;
                visited.insert(u);
                secret[u] = true;
                for (int v : graph[u]) {
                    if (!visited.count(v)) {
                        q.push(v);
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (secret[i])
                result.push_back(i);
        }
        return result;
    }
};

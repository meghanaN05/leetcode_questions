class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int> visited(v, 0);
        int count = 0;

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                count++;
                queue<int> q;
                q.push(i);
                visited[i] = 1;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int j = 0; j < v; j++) {
                        if (isConnected[node][j] == 1 && !visited[j]) {
                            visited[j] = 1;
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
};

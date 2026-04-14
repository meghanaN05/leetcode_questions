class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int LIMIT = 20000;

    bool dfs(int x, int y,vector<int>& target, unordered_set<long long>& blockedSet, unordered_set<long long>& visited) {
        long long key = (long long)x * 1000000 + y;
        if (blockedSet.count(key) || visited.count(key))
            return false;
        if (x < 0 || y < 0 || x >= 1000000 || y >= 1000000)
            return false;
        if (x == target[0] && y == target[1])
            return true;
        visited.insert(key);
        if (visited.size() > LIMIT)
            return true;
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (dfs(nx, ny, target, blockedSet, visited))
                return true;
        }

        return false;
    }

    bool check(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<long long> blockedSet;
        for (auto &b : blocked) {
            blockedSet.insert((long long)b[0] * 1000000 + b[1]);
        }

        unordered_set<long long> visited;
        return dfs(source[0], source[1], target, blockedSet, visited);
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        return check(blocked, source, target) &&
               check(blocked, target, source);
    }
};
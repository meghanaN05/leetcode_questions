class Solution {
public:
    int dfs(int i, int j, int cost, vector<vector<int>>& grid,int k, vector<vector<vector<int>>>& memo, int n, int m) {
        if (i < 0 || j < 0 || i >= n || j >= m) return -1e9;
        int addS = (grid[i][j] == 1 ? 1 : (grid[i][j] == 2 ? 2 : 0));
        int addC = (grid[i][j] == 1 ? 1 : (grid[i][j] == 2 ? 1 : 0));
        if (cost + addC > k) return -1e9;
        if (i == n - 1 && j == m - 1) return addS;
        if (memo[i][j][cost] != -1) return memo[i][j][cost];
        int down = dfs(i + 1, j, cost + addC, grid, k, memo, n, m);
        int right = dfs(i, j + 1, cost + addC, grid, k, memo, n, m);
        return memo[i][j][cost] = addS + max(down, right);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(m, vector<int>(k + 2, -1)));
        int ans = dfs(0, 0, 0, grid, k, memo, n, m);
        return ans < 0 ? -1 : ans;
    }
};
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int n, int m, int dir) {
        if (r < 0 || c < 0 || r >= n || c >= m || grid[r][c] == 1 || grid[r][c] == 2) return;
        grid[r][c] = 3;
        if (dir == 1) dfs(grid, r - 1, c, n, m, dir);
        else if (dir == 2) dfs(grid, r + 1, c, n, m, dir);
        else if (dir == 3) dfs(grid, r, c - 1, n, m, dir);
        else dfs(grid, r, c + 1, n, m, dir);
    }

    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for (auto& g : guards) grid[g[0]][g[1]] = 1;
        for (auto& w : walls) grid[w[0]][w[1]] = 2;
        for (auto& g : guards) {
            dfs(grid, g[0] - 1, g[1], n, m, 1);
            dfs(grid, g[0] + 1, g[1], n, m, 2);
            dfs(grid, g[0], g[1] - 1, n, m, 3);
            dfs(grid, g[0], g[1] + 1, n, m, 4);
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j] == 0) ++cnt;
        return cnt;
    }
};

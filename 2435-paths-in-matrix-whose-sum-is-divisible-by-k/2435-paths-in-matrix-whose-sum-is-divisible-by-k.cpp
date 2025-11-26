typedef long long ll;
const int MOD = 1e9 + 7;

class Solution {
public:
    int m, n, K;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> memo; 
    int dfs(int i, int j, int r) {
        if (i < 0 || j < 0) return 0;
        if (i == 0 && j == 0)
            return ( (grid[0][0] % K) == r );
        if (memo[i][j][r] != -1) return memo[i][j][r];
        int val = grid[i][j] % K;
        int prev = (r - val + K) % K;
        ll ways = 0;
        ways += dfs(i - 1, j, prev);
        ways += dfs(i, j - 1, prev);
        return memo[i][j][r] = ways % MOD;
    }

    int numberOfPaths(vector<vector<int>>& g, int k) {
        grid = g;
        K = k;
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<vector<int>>(n, vector<int>(K, -1)));
        return dfs(m - 1, n - 1, 0);
    }
};

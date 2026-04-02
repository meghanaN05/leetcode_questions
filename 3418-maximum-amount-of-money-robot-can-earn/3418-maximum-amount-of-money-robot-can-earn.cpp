class Solution {
public:
    int dp[501][501][3];
    const int NEG_INF = -1e9;
    int solve(int i, int j, int neu, int n, int m, vector<vector<int>>& coins) {
        if (i >= n || j >= m) return NEG_INF;
        if (i == n - 1 && j == m - 1) {
            if (coins[i][j] < 0 && neu > 0) return 0;
            return coins[i][j];
        }

        if (dp[i][j][neu] != NEG_INF) return dp[i][j][neu];
        int down = solve(i + 1, j, neu, n, m, coins);
        int right = solve(i, j + 1, neu, n, m, coins);
        int take = NEG_INF;
        if (down != NEG_INF || right != NEG_INF) {
            take = coins[i][j] + max(down, right);
        }
        int skip = NEG_INF;
        if (coins[i][j] < 0 && neu > 0) {
            int skipDown = solve(i + 1, j, neu - 1, n, m, coins);
            int skipRight = solve(i, j + 1, neu - 1, n, m, coins);
            if (skipDown != NEG_INF || skipRight != NEG_INF) {
                skip = max(skipDown, skipRight);
            }
        }

        return dp[i][j][neu] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(), m = coins[0].size();
        for (int i = 0; i < 501; i++)
            for (int j = 0; j < 501; j++)
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = NEG_INF;

        return solve(0, 0, 2, n, m, coins);
    }
};
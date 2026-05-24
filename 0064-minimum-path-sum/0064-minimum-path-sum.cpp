class Solution {
public:
  //space optimized version
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         vector<int> dp(m, 0);
        dp[0] = grid[0][0];
        for(int j = 1; j < m; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        for(int i = 1; i < n; i++) {
            dp[0] = dp[0] + grid[i][0];
            for(int j = 1; j < m; j++) {
                int up = dp[j];
                int left = dp[j - 1];
                dp[j] = grid[i][j] + min(up, left);
            }
        }
        return dp[m - 1];
    }
};
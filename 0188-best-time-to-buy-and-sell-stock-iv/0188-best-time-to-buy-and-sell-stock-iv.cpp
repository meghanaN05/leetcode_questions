class Solution {
public:
 int memo(int i, int buy, int t, vector<int>& prices,
             vector<vector<vector<int>>>& dp) {
        if (i == prices.size() || t == 0)
            return 0;
        if (dp[i][buy][t] != -1)
            return dp[i][buy][t];
        int profit;
        if (buy) {
            profit = max(
                -prices[i] + memo(i + 1, 0, t, prices, dp),
                memo(i + 1, 1, t, prices, dp)
            );
        } else {
            profit = max(
                prices[i] + memo(i + 1, 1, t - 1, prices, dp),
                memo(i + 1, 0, t, prices, dp)
            );
        }
        return dp[i][buy][t] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(k+1, -1))
        );
        return memo(0, 1, k, prices, dp);
    }
};
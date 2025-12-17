class Solution {
public:
    static const long long NEG = LLONG_MIN / 2;

    long long solve(int i, int k, int c,
                    vector<int>& prices,
                    vector<vector<vector<long long>>>& dp) {

        if (i == prices.size()) {
            if (c == 0) return 0;
            return NEG;
        }

        if (dp[i][k][c] != NEG)
            return dp[i][k][c];

        long long dontTake = solve(i + 1, k, c, prices, dp);
        long long take = NEG;

        if (k > 0) {
            if (c == 1) { // sell after buy
                take = prices[i] + solve(i + 1, k - 1, 0, prices, dp);
            }
            else if (c == 2) { // buy after sell
                take = -prices[i] + solve(i + 1, k - 1, 0, prices, dp);
            }
            else { // c == 0 (neutral)
                take = max(
                    -prices[i] + solve(i + 1, k, 1, prices, dp),
                     prices[i] + solve(i + 1, k, 2, prices, dp)
                );
            }
        }

        return dp[i][k][c] = max(take, dontTake);
    }

    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(
            n,
            vector<vector<long long>>(k + 1, vector<long long>(3, NEG))
        );

        return solve(0, k, 0, prices, dp);
    }
};

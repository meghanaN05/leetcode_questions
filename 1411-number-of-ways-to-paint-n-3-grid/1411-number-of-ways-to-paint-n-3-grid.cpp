class Solution {
public:
    int mod = 1e9 + 7;
    int numOfWays(int n) {
        vector<vector<long long>> dp(n, vector<long long>(3, 0));
        dp[0][1] = dp[0][2] = 6;
        for(int i = 1; i < n; i++) {
            dp[i][2] = ((dp[i - 1][1] * 2LL) % mod + (dp[i - 1][2] * 2LL) % mod) % mod;
            dp[i][1] = ((dp[i - 1][1] * 3LL) % mod + (dp[i - 1][2] * 2LL) % mod) % mod;
        }
        return (dp[n - 1][1] + dp[n - 1][2]) % mod;
    }
};

class Solution {
    static const int mod = 1e9 + 7;
    vector<long long> fact, inverse, inversefact;

    void precomputation(int n) {
        fact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i % mod;
        }

        inverse.assign(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            inverse[i] = mod - (mod / i) * inverse[mod % i] % mod;
        }

        inversefact.assign(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            inversefact[i] = inversefact[i - 1] * inverse[i] % mod;
        }
    }

public:
    int countBalancedPermutations(const string &s) {
        int n = s.size(), sum = 0;
        for (char c : s) sum += c - '0';
        if (sum % 2 == 1) return 0;

        precomputation(n);
        int halfsum = sum / 2, halflen = n / 2;

        vector<vector<int>> dp(halfsum + 1, vector<int>(halflen + 1));
        dp[0][0] = 1;

        vector<int> digits(10);
        for (char c : s) {
            int d = c - '0';
            digits[d]++;
            for (int i = halfsum; i >= d; i--) {
                for (int j = halflen; j > 0; j--) {
                    dp[i][j] = (dp[i][j] + dp[i - d][j - 1]) % mod;
                }
            }
        }

        long long result = dp[halfsum][halflen];
        result = result * fact[halflen] % mod * fact[n - halflen] % mod;
        for (int i : digits)
            result = result * inversefact[i] % mod;

        return result;
    }
};

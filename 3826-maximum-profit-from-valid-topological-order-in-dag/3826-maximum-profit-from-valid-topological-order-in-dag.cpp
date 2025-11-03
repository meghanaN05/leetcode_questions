class Solution {
public:
    int n;
    vector<int> pre, score;
    vector<long long> dp;

    long long dfs(int mask) {
        if (mask == (1 << n) - 1) return 0; 
        if (dp[mask] != -1) return dp[mask];

        long long best = 0;
        int pos = __builtin_popcount(mask) + 1;

        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)) && ((mask & pre[u]) == pre[u])) {
                best = max(best, 1LL * score[u] * pos + dfs(mask | (1 << u)));
            }
        }

        return dp[mask] = best;
    }

    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        this->n = n;
        this->score = score;
        pre.assign(n, 0);
        dp.assign(1 << n, -1);

        for (auto &e : edges) {
            pre[e[1]] |= (1 << e[0]); 
        }

        return (int)dfs(0);
    }
};

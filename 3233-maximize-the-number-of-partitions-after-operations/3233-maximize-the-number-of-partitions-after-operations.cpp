class Solution {
public:
    unordered_map<long long, int> dp;
    string s;
    int K;
    int n;

    int dfs(int i, int mask, bool canChange) {
        if (i == n) return mask ? 1 : 0; 

        long long key = ((long long)i << 32) | ((long long)mask << 1) | (canChange ? 1LL : 0LL);
        if (dp.count(key)) return dp[key];

        int ch = s[i] - 'a';
        int newMask = mask | (1 << ch);
        int res;
        if (__builtin_popcount(newMask) > K) {
          
            res = 1 + dfs(i + 1, 1 << ch, canChange);
        } else {
            res = dfs(i + 1, newMask, canChange);
        }
        if (canChange) {
            for (int c = 0; c < 26; ++c) {
                if (c == ch) continue;
                int altMask = mask | (1 << c);
                if (__builtin_popcount(altMask) > K) {
                    res = max(res, 1 + dfs(i + 1, 1 << c, false));
                } else {
                    res = max(res, dfs(i + 1, altMask, false));
                }
            }
        }

        return dp[key] = res;
    }

    int maxPartitionsAfterOperations(string s_, int k) {
        s = s_;
        K = k;
        n = s.size();
        dp.clear();
        return dfs(0, 0, true);
    }
};

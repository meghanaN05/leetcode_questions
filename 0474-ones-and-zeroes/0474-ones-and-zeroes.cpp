class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < strs.size(); i++) {
            int ones = 0, zeros = 0;
            for (char c : strs[i]) {
                if (c == '1') ones++;
                else zeros++;
            }
            ans.push_back({zeros, ones});
        }
        vector<vector<vector<int>>> memo(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(ans, 0, m, n, memo);
    }

    int helper(vector<vector<int>>& ans, int idx, int m, int n, vector<vector<vector<int>>>& memo) {
        if (idx == ans.size()) return 0;
        if (memo[idx][m][n] != -1) return memo[idx][m][n];
        int zeros = ans[idx][0];
        int ones = ans[idx][1];
        int notTake = helper(ans, idx + 1, m, n, memo);
        int take = 0;
        if (m >= zeros && n >= ones)
            take = 1 + helper(ans, idx + 1, m - zeros, n - ones, memo);

        return memo[idx][m][n] = max(take, notTake);
    }
};

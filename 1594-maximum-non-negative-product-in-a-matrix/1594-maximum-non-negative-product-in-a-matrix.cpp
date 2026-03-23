class Solution {
public:
    int MOD = 1e9 + 7;
    int n, m;

    vector<vector<pair<long long,long long>>> dp;
    pair<long long,long long> solve(int i, int j, vector<vector<int>>& grid){
        if(i >= n || j >= m)
            return {LLONG_MIN, LLONG_MAX};
        if(i == n-1 && j == m-1)
            return {grid[i][j], grid[i][j]};
        if(dp[i][j].first != LLONG_MIN)
            return dp[i][j];
        auto down = solve(i+1, j, grid);
        auto right = solve(i, j+1, grid);
        long long mx = LLONG_MIN, mn = LLONG_MAX;
        if(down.first != LLONG_MIN){
            long long a = down.first * grid[i][j];
            long long b = down.second * grid[i][j];
            mx = max(mx, max(a,b));
            mn = min(mn, min(a,b));
        }
        if(right.first != LLONG_MIN){
            long long a = right.first * grid[i][j];
            long long b = right.second * grid[i][j];
            mx = max(mx, max(a,b));
            mn = min(mn, min(a,b));}

        return dp[i][j] = {mx, mn};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        dp.assign(n, vector<pair<long long,long long>>(m, {LLONG_MIN, LLONG_MIN}));
        auto res = solve(0,0,grid);
        if(res.first < 0) return -1;
        return res.first % MOD;
    }
};
class Solution {
public:    
    vector<vector<int>> dp;
    int findLowestCoins(vector<int> &coins, int cur, int amount) {
        if (cur == coins.size() || amount <= 0)
            return (amount == 0) ? 0 : INT_MAX;
        if (dp[cur][amount] != -1)
            return dp[cur][amount];
        int res;
        if (coins[cur] > amount) {
            res = findLowestCoins(coins, cur + 1, amount);
        }
        else {
            int take = findLowestCoins(coins, cur, amount - coins[cur]);
            int notTake = findLowestCoins(coins, cur + 1, amount);
            if (take != INT_MAX) take += 1;
            res = min(take, notTake);
        }
        return dp[cur][amount] = res;
    }

    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size() + 1, vector<int>(amount + 1, -1));
        int res = findLowestCoins(coins, 0, amount);
        return res == INT_MAX ? -1 : res;
    }
};
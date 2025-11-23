class Solution {
public:
    int solve(int i, int rem, vector<vector<int>>& dp, vector<int>& nums, int n) {
        if (i == n) {
            return (rem == 0 ? 0 : INT_MIN); 
        }
        if (dp[i][rem] != -1) return dp[i][rem];
        int notTake = solve(i + 1, rem, dp, nums, n);
        int newRem = (rem + nums[i]) % 3;
        int take = nums[i] + solve(i + 1, newRem, dp, nums, n);
        return dp[i][rem] = max(take, notTake);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans = solve(0, 0, dp, nums, n);
        return ans < 0 ? 0 : ans;   
    }
};

class Solution {
public:
    int n;

    int solve(int i, vector<int>& nums, vector<int>& memo) {
        if (i >= n) return 0;        
        if (memo[i] != -1) return memo[i];  
        int rob_this = nums[i] + solve(i + 2, nums, memo);
        int skip_this = solve(i + 1, nums, memo);
        memo[i] = max(rob_this, skip_this);
        return memo[i];
    }

    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> memo(n, -1);
        return solve(0, nums, memo);
    }
};

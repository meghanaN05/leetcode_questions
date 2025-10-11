class Solution {
public:
    int solve(int i, int end, vector<int>& nums, vector<int>& memo) {
        if (i > end) return 0;
        if (memo[i] != -1) return memo[i];

        int rob_this = nums[i] + solve(i + 2, end, nums, memo);
        int skip_this = solve(i + 1, end, nums, memo);

        memo[i] = max(rob_this, skip_this);
        return memo[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> memo1(n, -1);
        int case1 = solve(0, n - 2, nums, memo1); 

        vector<int> memo2(n, -1);
        int case2 = solve(1, n - 1, nums, memo2); 

        return max(case1, case2);
    }
};

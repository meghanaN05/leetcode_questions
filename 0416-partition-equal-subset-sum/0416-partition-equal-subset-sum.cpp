
class Solution {
public:
    bool dp(int i, int x, vector<int>& nums, vector<vector<int>>& memo) {
        if (x == 0) return true;
        if (i >= nums.size() || x < 0) return false;
        if (memo[i][x] != -1) return memo[i][x];

        bool take = dp(i + 1, x - nums[i], nums, memo);
        bool notTake = dp(i + 1, x, nums, memo);

        return memo[i][x] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int x = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(x + 1, -1));
        return dp(0, x, nums, memo);
    }
};

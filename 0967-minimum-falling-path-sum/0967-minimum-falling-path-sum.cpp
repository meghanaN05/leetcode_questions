class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix.back(); 
        
        for (int i = n - 2; i >= 0; i--) {
            vector<int> new_dp(n);
            for (int j = 0; j < n;j++) {
                int best = dp[j]; 
                if (j > 0) best = min(best, dp[j - 1]); 
                if (j < n - 1) best = min(best, dp[j + 1]);
                new_dp[j] = matrix[i][j] + best;
            }
            dp = new_dp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};

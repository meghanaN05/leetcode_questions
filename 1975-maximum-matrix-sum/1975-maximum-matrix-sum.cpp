class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        long long sum = 0;
        int neg = 0;
        int minAbs = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x = matrix[i][j];
                if (x < 0) neg++;
                sum += abs(x);
                minAbs = min(minAbs, abs(x));
            }
        }

        if (neg % 2 == 1)
            return sum - 2LL * minAbs;

        return sum;
    }
};

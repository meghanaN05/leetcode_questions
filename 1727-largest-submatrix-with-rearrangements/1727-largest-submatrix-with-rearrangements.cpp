class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int ans = 0;
        for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
         if(matrix[i][j] == 1 && i > 0)
           matrix[i][j] += matrix[i-1][j];
            }
            vector<int> v = matrix[i];
            sort(v.begin(), v.end(), greater<int>());
            for(int j = 0; j < n; j++) {
                ans = max(ans, v[j] * (j + 1));
            }
        }

        return ans;
    }
};
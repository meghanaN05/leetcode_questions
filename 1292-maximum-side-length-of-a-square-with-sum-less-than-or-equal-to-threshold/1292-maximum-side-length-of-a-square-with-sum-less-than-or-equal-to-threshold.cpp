class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pref(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pref[i][j] = mat[i-1][j-1]+ pref[i-1][j]+ pref[i][j-1]- pref[i-1][j-1];
            }
        }
        int low = 0, high = min(n, m), ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            bool found = false;
            for (int i = mid; i <= n && !found; i++) {
                for (int j = mid; j <= m; j++) {
                    int sum = pref[i][j] - pref[i-mid][j]- pref[i][j-mid]+ pref[i-mid][j-mid];
                    if (sum <= threshold) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

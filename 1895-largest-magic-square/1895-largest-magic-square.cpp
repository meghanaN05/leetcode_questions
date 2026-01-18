class Solution {
public:
    bool isMagic(vector<vector<int>>& grid, int i, int j, int k) {
        int sum = 0;
        for (int x = j; x < j + k; x++) {
            sum += grid[i][x];
        }
        for (int x = i; x < i + k; x++) {
            int curr = 0;
            for (int y = j; y < j + k; y++) {
                curr += grid[x][y];
            }
            if (curr != sum) return false;
        }
        for (int y = j; y < j + k; y++) {
            int curr = 0;
            for (int x = i; x < i + k; x++) {
                curr += grid[x][y];
            }
            if (curr != sum) return false;
        }
        int curr = 0;
        for (int x = 0; x < k; x++) {
            curr += grid[i + x][j + x];
        }
        if (curr != sum) return false;
        curr = 0;
        for (int x = 0; x < k; x++) {
            curr += grid[i + x][j + k - 1 - x];
        }
        if (curr != sum) return false;
        return true;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 1;  
        for (int k = 2; k <= min(m, n); k++) {
            for (int i = 0; i <= m - k; i++) {
                for (int j = 0; j <= n - k; j++) {
                    if (isMagic(grid, i, j, k)) {
                        ans = k;
                    }
                }
            }
        }
        return ans;
    }
};

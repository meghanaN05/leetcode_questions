class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        if (r < 3 || c < 3) return 0;

        int ans = 0;

        for (int i = 0; i <= r - 3; i++) {
            for (int j = 0; j <= c - 3; j++) {

                bool used[10] = {0};
                bool ok = true;

                // 1️ Check numbers 1 to 9 (no duplicates)
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int v = grid[i + x][j + y];
                        if (v < 1 || v > 9 || used[v]) {
                            ok = false;
                            break;
                        }
                        used[v] = true;
                    }
                    if (!ok) break;
                }
                if (!ok) continue;

                // 2️ Target sum (first row)
                int s = grid[i][j] + grid[i][j+1] + grid[i][j+2];

                // 3️ Check rows & columns
                for (int k = 0; k < 3; k++) {
                    if (grid[i+k][j] + grid[i+k][j+1] + grid[i+k][j+2] != s ||
                        grid[i][j+k] + grid[i+1][j+k] + grid[i+2][j+k] != s) {
                        ok = false;
                        break;
                    }
                }

                // 4️ Check diagonals
                if (grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2] != s ||
                    grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j] != s)
                    ok = false;

                if (ok) ans++;
            }
        }
        return ans;
    }
};

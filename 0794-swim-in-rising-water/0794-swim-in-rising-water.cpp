class Solution {
public:

int n;
vector<vector<int>> grid;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool dfs(int x, int y, int t, vector<vector<int>>& vis) {
if (x == n - 1 && y == n - 1) return true;
vis[x][y] = 1;
for (int k = 0; k < 4; k++) {
int nx = x + dx[k], ny = y + dy[k];
if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny] && grid[nx][ny] <= t) {
if (dfs(nx, ny, t, vis)) return true;
}
}
return false;
}

int swimInWater(vector<vector<int>>& g) {
grid = g;
n = grid.size();
int low = grid[0][0], high = n * n - 1, ans = -1;
while (low <= high) {
    int mid = (low + high) / 2;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if (grid[0][0] <= mid && dfs(0, 0, mid, vis)) {
        ans = mid;
        high = mid - 1;
    } else {
        low = mid + 1;
    }
}
return ans;

}
};


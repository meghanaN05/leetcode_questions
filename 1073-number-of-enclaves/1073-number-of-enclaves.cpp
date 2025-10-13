
class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(int i, int j, vector<vector<int>>& grid, int m, int n) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return;
        grid[i][j] = 0; 
        for(int k = 0; k < 4; k++){
            dfs(i + dx[k], j + dy[k], grid, m, n);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            dfs(i, 0, grid, m, n);
            dfs(i, n-1, grid, m, n);
        }
        for(int j = 0; j < n; j++){
            dfs(0, j, grid, m, n);
            dfs(m-1, j, grid, m, n);
        }

      
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) count++;
            }
        }
        return count;
    }
};

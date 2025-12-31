class Solution {
public:
int n;
int m;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool dfs(vector<vector<int>> &grid, int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1)
        return false;
    if (i == n - 1)
        return true;
    grid[i][j] = 1; 
    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];
        if (dfs(grid, new_i, new_j))
            return true;
    }
    return false;
}

bool possible(vector<vector<int>>& cells,int mid){
      vector<vector<int>> grid(n, vector<int>(m));
      for(int i=0;i<=mid;i++){
        int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
      }
      for(int j=0;j<m;j++){
        if(grid[0][j]==0 && dfs(grid,0,j)) return true;
      }
      return false;
}
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n=row;
        m=col;
        int ans=0;
        int l=0,r=cells.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(cells,mid)){
                ans=mid+1;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
         return ans;
    }
};
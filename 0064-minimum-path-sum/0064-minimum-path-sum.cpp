class Solution {
public:
  int solve(int n,int m,vector<vector<int>>& grid, vector<vector<int>>&memo){
    if(n==0 && m==0) return grid[n][m];
    if(n<0 || m<0) return 1e9;
    if(memo[n][m]!=-1) return memo[n][m];
    int c1=grid[n][m]+solve(n-1,m,grid,memo);
    int c2=grid[n][m]+solve(n,m-1,grid,memo);
    return memo[n][m]=min(c1,c2);
  }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,memo);
    }
};
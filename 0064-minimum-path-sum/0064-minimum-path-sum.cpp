class Solution {
public:
int solve(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&memo){
    if(i==0 && j==0) return grid[i][j];
    if(i<0 || j<0) return 1e9;
    if(memo[i][j]!=-1) return memo[i][j];
    int up=grid[i][j]+solve(i-1,j,grid,memo);
    int left=grid[i][j]+solve(i,j-1,grid,memo);
    return memo[i][j]=min(up,left);
}
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,memo);
    }
};
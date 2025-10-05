class Solution {
public:   
    int unique(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&memo){
         if(i<0 || j<0 ) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
       
        
        if(memo[i][j]!=-1) return memo[i][j];
        return memo[i][j]=unique(i-1,j,obstacleGrid,memo)+unique(i,j-1,obstacleGrid,memo);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid[0].size();
        int n=obstacleGrid.size();
        vector<vector<int>>memo(n,vector<int>(m,-1));
        return unique(n-1,m-1,obstacleGrid,memo);

    }
};
class Solution {
public:

    bool canPartitionGrid(vector<vector<int>>& grid) {
       long long sum=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
        }
        if(sum%2!=0) return false;
        long long newsum=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
               newsum+=grid[i][j];
               if(newsum==sum/2) return true;
            }
        }
       newsum = 0;
        
        for (int j = 0; j < m-1; j++) {
            for (int i = 0; i <n; i++)
                newsum += grid[i][j];
            if (newsum == sum/2) return true;
        }
        
        return false;
    }
};
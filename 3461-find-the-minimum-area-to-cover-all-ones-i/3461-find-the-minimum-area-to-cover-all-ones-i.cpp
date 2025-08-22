class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mini_m=m;
        int mini_n=n;
        int maxi_m=0;
        int maxi_n=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    mini_n=min(mini_n,i);
                 mini_m=min(mini_m,j);
                 maxi_n=max(maxi_n,i);
                 maxi_m=max(maxi_m,j);
                }
            }
        }
         return (maxi_n - mini_n + 1) * (maxi_m - mini_m+ 1);
    }
};
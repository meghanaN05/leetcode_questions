//binary search approach
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int n=grid.size(),m=grid[0].size();
       int i=n-1;
       int j=0;
       while(i>=0 && i<n && j>=0 && j<m){
        if(grid[i][j]<0){
            count+=(m-j);
            i=i-1;
        }
        else{
            j=j+1;
        }
       }
            return count;
    }
};
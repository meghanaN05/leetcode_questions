class Solution {
public:
int n;
void sortdiagonal(int r,int c,vector<vector<int>>& grid,bool ascending){
    vector<int>ans;
    int i=r;
    int j=c;
    while(i<n && j<n){
       ans.push_back(grid[i][j]);
       i++;
       j++;
    }
    if(ascending==true){
        sort(ans.begin(),ans.end());
    }
    else{
         sort(ans.rbegin(),ans.rend());
    }
    i=r;
    j=c;
    for(int val:ans){
       grid[i][j]=val;
       i++;
       j++;
    }
}
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
         n=grid.size();
        for(int i=0;i<n;i++){
            sortdiagonal(i,0,grid,false);

        }
        for(int j=1;j<n;j++){
            sortdiagonal(0,j,grid,true);
        }
        return grid;
    }
};
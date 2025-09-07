class Solution {
public:
vector<int>row={-1,0,1,0};
vector<int>col={0,1,0,-1};
void dfs(int r,int c,vector<vector<int>>& ans,vector<vector<int>>& image,int iC,int nC){
    ans[r][c]=nC;
    int n=image.size();
    int m=image[0].size();
    for(int i=0;i<4;i++){
        int nrow=r+row[i];
        int ncol=c+col[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==iC &&
        ans[nrow][ncol]!=nC){
            dfs(nrow,ncol,ans,image,iC,nC);

        }
    }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iC=image[sr][sc];
        vector<vector<int>>ans=image;
        dfs(sr,sc,ans,image,iC,color);
        return ans;
    }
};
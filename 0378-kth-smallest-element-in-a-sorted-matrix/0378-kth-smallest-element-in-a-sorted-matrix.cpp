class Solution {
  public:
  int clk(vector<vector<int>> &mat, int mid,int n,int m){
      int cnt=0,c=m-1;
      for(int i=0;i<n;i++){
          while(c>=0 && mat[i][c]>mid) c--;
          cnt+=(c+1);
      }
      return cnt;
  }
    int kthSmallest(vector<vector<int>> &mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        int l=mat[0][0];
        int r=mat[n-1][m-1];
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(clk(mat,mid,n,m)>=k){
                ans=mid;
                r=mid-1;
            }
            else{
               l=mid+1;
            }
            
        }
        return ans;
        
    }
};

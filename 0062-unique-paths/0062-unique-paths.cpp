class Solution {
public:
int unique(int m,int n,vector<vector<int>>&memo){
    if(n<0 || m<0) return 0;
    if(n==0 && m==0) return 1;
    if(memo[m][n]!=-1) return memo[m][n];
    return memo[m][n]=unique(m-1,n,memo)+unique(m,n-1,memo);
}
    int uniquePaths(int m, int n) {
        vector<vector<int>>memo(m,vector<int>(n,-1));
        return unique(m-1,n-1,memo);
    }

};
class NumMatrix {
public:    
vector<vector<int>> pre;
    int n, m;
    NumMatrix(vector<vector<int>>& matrix) {
          int n = matrix.size();
        int m = (n == 0) ? 0 : matrix[0].size();
         pre.assign(n, vector<int>(m, 0));

        if (n == 0 || m == 0) return;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                pre[i][j] = matrix[i][j];

                if (i > 0) pre[i][j] += pre[i-1][j];
                if (j > 0) pre[i][j] += pre[i][j-1];
                if (i > 0 && j > 0) pre[i][j] -= pre[i-1][j-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=pre[row2][col2];
        if(row1>0)
        ans-=pre[row1-1][col2];
        if(col1>0)
        ans-=pre[row2][col1-1];
        if(row1>0 && col1>0)
        ans+=pre[row1-1][col1-1];
         return ans;
    }
    
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
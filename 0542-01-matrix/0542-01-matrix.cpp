class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0) q.push({i,j});
                else mat[i][j] = INT_MAX;
            }
        }
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni >= 0 && nj >= 0 && ni < m && nj < n){
                    if(mat[ni][nj] > mat[i][j] + 1){
                        mat[ni][nj] = mat[i][j] + 1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return mat;
    }
};

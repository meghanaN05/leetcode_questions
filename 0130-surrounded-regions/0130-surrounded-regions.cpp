class Solution {
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    void dfs(int i, int j, vector<vector<char>>& board, int m, int n) {
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;
        board[i][j] = '@';
        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            dfs(ni, nj, board, m, n);
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m == 0) return;
        int n = board[0].size();
        if(n == 0) return;

        
        for(int i = 0; i < m; i++){
            dfs(i, 0, board, m, n);
            dfs(i, n - 1, board, m, n);
        }
        for(int j = 0; j < n; j++){
            dfs(0, j, board, m, n);
            dfs(m - 1, j, board, m, n);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '@') board[i][j] = 'O';
                else if(board[i][j] == 'O') board[i][j] = 'X';
            }
        }
    }
};

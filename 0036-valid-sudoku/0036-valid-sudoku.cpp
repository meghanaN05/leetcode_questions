class Solution {
public:
    bool traversal(vector<vector<char>>& board,int sr,int er,int sc,int ec){
        set<char> st;
        for (int i = sr; i < er; i++) {
            for (int j = sc; j < ec; j++) {
                if (board[i][j] == '.') continue;
                if (st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
    
        for (int i = 0; i < 9; i++) {
            set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        for (int i = 0; i < 9; i++) {
            set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] == '.') continue;
                if (st.find(board[j][i]) != st.end()) {
                    return false;
                }
                st.insert(board[j][i]);
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!traversal(board, i, i + 3, j, j + 3)) return false;
            }
        }

        return true;
    }
};

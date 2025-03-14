class Solution {
public:
   int dx[4]={0,0,1,-1};
   int dy[4]={1,-1,0,0};
   bool helper(int r,int c,vector<vector<char>>& board, string word){
    int n=board.size(),m=board[0].size();
    if(word.size()==0)  return true;
    if(r>=n || r<0 || c>=m || c<0 || board[r][c]!=word[0]){
        return false;
    }
    char ch=board[r][c];
    board[r][c]='*';
    string s=word.substr(1);
    bool ans=false;
    for(int i=0;i<4;i++){
        int nr=r+dx[i];
        int nc=c+dy[i];
        ans|=helper(nr,nc,board,s);

    }
    board[r][c]=ch;
    return ans;
   }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                  bool ans=helper(i,j,board,word);
                  if(ans) return true;
                }
                
            }
        }
        return false;
    }
};
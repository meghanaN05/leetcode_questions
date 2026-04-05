class Solution {
public:
    bool judgeCircle(string moves) {
         int i=0,j=0;
         int k=0;
         while(k<moves.size()){
            if(moves[k]=='U')i--;
            if(moves[k]=='D')i++;
            if(moves[k]=='L')j--;
            if(moves[k]=='R')j++;
            k++;
         }
         return (i==0 && j==0);
       
    }
};
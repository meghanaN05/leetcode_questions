class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int r=strs.size();
        int c=strs[0].size();
        int d=0;
        vector<int>srt(r,false);
        for(int j=0;j<c;j++){
            bool deleted=0;
            for(int i=0;i<r-1;i++){
                if(!srt[i] && strs[i][j]>strs[i+1][j]){
                    d++;
                    deleted=true;
                    break;
                }
            }
            if(deleted){
                continue;
            }
            for(int i=0;i<r-1;i++){
                srt[i]=srt[i]|(strs[i][j]<strs[i+1][j]);
            }
        }
        return d;
    }
};
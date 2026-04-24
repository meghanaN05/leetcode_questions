class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int maxi=0;
        int cntl=0;
        int cntr=0;
        for(int i=0;i<moves.size();i++){
            if(moves[i]=='L') cntl++;
            if(moves[i]=='R') cntr++;
            if(moves[i]=='_'){
                maxi++;
            }

        }
        return abs(cntl-cntr)+maxi;
    }
};
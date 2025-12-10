class Solution {
public:
int MOD=1e9+7;
    int countPermutations(vector<int>& complexity) {
        long long cnt=1;
        for(int i=1;i<complexity.size();i++){
            if(complexity[i]<=complexity[0]) return 0;
            cnt=cnt*i%MOD;
        }
        return cnt;
    }
};
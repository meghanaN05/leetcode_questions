class Solution {
public:
    int md = 1e9+7;
    int numTilings(int n) {
        vector<int>v(1001);
        v[0] = 1;
        v[1] = 1;
        v[2] = 2;
        for(int i=3;i<=n;i++){
            v[i] = (v[i-1]*2LL%md + v[i-3])%md;
        }
        return v[n];
    }
};
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>a(n+1);
        for(int i=0;i<=n;i++){
            a[i]= __builtin_popcount(i);
        }
        return a;
    }
};
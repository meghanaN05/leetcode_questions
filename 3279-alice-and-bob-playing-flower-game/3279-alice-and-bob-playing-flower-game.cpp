class Solution {
public:
    long long flowerGame(int n, int m) {
     if(n==1 && m==1) return 0;
        long long ans=(long long)n*m/2;
        return ans;
    }
};
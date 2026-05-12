class Solution {
public:
//fibonacci series:f(n-1)+f(n-2)
    int climbStairs(int n) {
        if(n<=2) return n;
        int x=2,y=1;
        int z;
        for(int i=3;i<=n;i++){
             z=x+y;
             y=x;
             x=z;
        }
        return z;
    }
};
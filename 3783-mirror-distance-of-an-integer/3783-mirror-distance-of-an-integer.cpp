class Solution {
public:
   int rev(int n){
    int rr=0;
    while(n!=0){
        int digit=n%10;
        rr=rr*10+digit;
        n=n/10;
    }
    return rr;
   }
    int mirrorDistance(int n) {
        return abs(n-rev(n));
    }
};
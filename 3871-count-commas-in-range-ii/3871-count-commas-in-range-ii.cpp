class Solution {
public:
    long long countCommas(long long n) {
       long long ans = 0;
        for(long long k = 1; ; k++){
            long long start = pow(10,3*k);
            if(start>n) break;
            long long end = pow(10,3*(k+1))-1;
            long long count = min(n,end)-start+1;
            ans += count * k;
        }
        return ans;
    }
};
class Solution {
public:
    int concatenatedBinary(int n) {
        const long long MOD = 1e9 + 7;  
        long long res = 0;
        for(int i = 1; i <= n; i++) {
            int digit = log2(i) + 1;     
            res = ((res << digit) % MOD + i) % MOD;
        }
        return (int)res;
    }
};
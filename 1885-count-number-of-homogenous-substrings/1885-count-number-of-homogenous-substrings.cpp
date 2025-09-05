class Solution {
public:
    const int MOD = 1000000007;

    int countHomogenous(string s) {
        long long maxi = 0; 
        long long cnt = 0;  
        int n = s.size();
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == s[i+1]) {
                cnt++;
                maxi += cnt;
                if (maxi >= MOD) maxi -= MOD;  
            }
            else {
                cnt = 0;
            }
        }
        return (maxi + n) % MOD;
    }
};

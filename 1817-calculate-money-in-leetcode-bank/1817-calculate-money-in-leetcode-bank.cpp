class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        int week = 1;
        while (n > 0) {
            int d= min(7, n);  
            for (int i = 0; i < d; i++) {
                ans += week + i;
            }
            n -=d;
            week++;
        }
        return ans;
    }
};

class Solution {
public:
    double helper(double a, long long b) {
        if (b == 0) return 1;
        double temp = helper(a, b / 2);
        temp *= temp;
        if (b % 2 != 0) temp *= a;
        return temp;
    }

    double myPow(double x, int n) {
        long long N = n;  
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return helper(x, N);
    }
};

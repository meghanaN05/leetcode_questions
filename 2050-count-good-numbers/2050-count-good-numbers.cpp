class Solution {
public:
    const int M = 1e9 + 7;

    long long Findpower(long long a, long long b) {
        if (b == 0) return 1;
        long long half = Findpower(a, b / 2);
        long long result = (half * half) % M;
        if (b % 2 == 1) {
            result = (result * a) % M;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long p1 = Findpower(5, (n + 1) / 2);
        long long p2 = Findpower(4, n / 2);
        return (p1 * p2) % M;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;

    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    bool possible(long long mid, int n, int a, int b) {
        long long cnta = mid / a;
        long long cntb = mid / b;
        long long cntc = mid / lcm(a, b);
        return cnta + cntb - cntc >= n;
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long low = 1, high = 1e18, ans = -1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (possible(mid, n, a, b)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans % mod;
    }
};

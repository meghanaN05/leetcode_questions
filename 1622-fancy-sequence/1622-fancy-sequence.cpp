class Fancy {
public:
    vector<long long> arr;
    long long add = 0, mul = 1;
    const long long MOD = 1000000007;

    long long modInverse(long long x) {
        long long res = 1, p = MOD - 2;
        while (p) {
            if (p & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            p >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};
class Solution {
public:
    string toBase(int n, int base) {
        string res = "";
        while (n > 0) {
            res += to_string(n % base);
            n /= base;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool isStrictlyPalindromic(int n) {
        for (int base = 2; base <= n - 2; base++) {
            string s = toBase(n, base);
            string rev = s;
            reverse(rev.begin(), rev.end());
            if (s != rev) return false;
        }
        return true;
    }
};

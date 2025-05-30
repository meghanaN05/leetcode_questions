class Solution {
public:
    bool helper(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 3 != 0) return false;
        return helper(n / 3);
    }

    bool isPowerOfThree(int n) {
        return helper(n);
    }
};

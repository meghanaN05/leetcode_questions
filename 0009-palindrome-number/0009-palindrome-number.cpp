class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers cannot be palindromes
        if (x < 0) {
            return false;
        }

        int original = x;  // Store the original value of x
        long long sum = 0;       // Reversed number

        // Reverse the digits of x
        while (x != 0) {
            int remainder = x % 10;
            sum = 10 * sum + remainder;
            x = x / 10;
        }

        // Compare reversed number with the original
        return sum == original;
    }
};

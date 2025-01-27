
class Solution {
public:
    int reverse(int x) {
        long long rev = 0; // Use long long to handle intermediate overflow
        while (x != 0) {
            int rem = x % 10;

            // Check for overflow before updating rev
            if (rev > (INT_MAX / 10) || (rev < (INT_MIN / 10))) {
                return 0; // Return 0 if reversing causes overflow
            }

            rev = rev * 10 + rem;
            x = x / 10;
        }

        return (rev < INT_MIN || rev > INT_MAX) ? 0 : rev; // Final overflow check
    }
};

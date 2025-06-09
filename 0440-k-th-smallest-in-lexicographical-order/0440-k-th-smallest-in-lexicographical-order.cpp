class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        int i = 1;
        while (i < k) {
            long gap = getGap(curr, curr + 1, n);
            if (i + gap <= k) {
                // Skip this entire subtree
                i += gap;
                curr += 1;
            } else {
                // Dive into this subtree
                i += 1;
                curr *= 10;
            }
        }
        return int(curr);
    }

private:
    long getGap(long a, long b, int n) {
        long gap = 0;
        while (a <= n) {
            gap += min((long)n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }
};

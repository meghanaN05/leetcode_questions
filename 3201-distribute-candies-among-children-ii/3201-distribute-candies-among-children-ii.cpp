class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ways = 0;

    
        int min1 = max(0, n - 2*limit);
        int max1 = min(n, limit);

        for(int i = min1; i <= max1; i++) { 

            int N = n-i; 

            int min2 = max(0, N - limit);
            int max2 = min(N, limit);

            ways += max2 - min2 + 1;
        }

        return ways;
    }
};
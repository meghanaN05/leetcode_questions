class Solution {
public:
    int sumofdivisors(int x) {
        int cnt = 0, sum = 0;
        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                int d1 = i;
                int d2 = x / i;
                if (d1 == d2) {
                    cnt++;
                    sum += d1;
                } else {
                    cnt += 2;
                    sum += d1 + d2;
                }
            }
            if (cnt > 4) return 0;
        }
        return (cnt == 4) ? sum : 0;
    }

    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) {
            sum += sumofdivisors(x);
        }
        return sum;
    }
};

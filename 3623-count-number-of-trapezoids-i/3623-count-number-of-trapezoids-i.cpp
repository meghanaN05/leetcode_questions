class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> pointNum;
        const long long mod = 1e9 + 7;
        for (auto& point : points) {
            pointNum[point[1]]++;
        }
        long long ans = 0;
        long long sum = 0;
        for (auto& [_, cnt] : pointNum) {
            long long edge = cnt * (cnt - 1) / 2;
            edge %= mod;     
            ans = (ans + (edge * sum) % mod) % mod;

            sum = (sum + edge) % mod;
        }

        return ans % mod;
    }
};

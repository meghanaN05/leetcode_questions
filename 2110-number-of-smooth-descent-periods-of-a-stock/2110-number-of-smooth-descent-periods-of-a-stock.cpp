class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = prices.size();
        long long cnt = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] == prices[i - 1] - 1) {
                cnt++;
                ans += cnt;
            } else {
                cnt = 0;
            }
        }
        return ans;
    }
};

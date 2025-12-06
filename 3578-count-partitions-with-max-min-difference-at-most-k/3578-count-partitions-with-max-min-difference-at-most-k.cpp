class Solution {
public:
    long long mod = 1e9 + 7;
    vector<long long> memo, prefix;
    vector<int> L;
    long long solve(int i) {
        if (i == 0) return 1;           
        if (memo[i] != -1) return memo[i];
        long long left = L[i];         
        long long sumRange = (prefix[i - 1] - (left > 0 ? prefix[left - 1] : 0) + mod) % mod;
        return memo[i] = sumRange;
    }
    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        memo.assign(n + 1, -1);
        prefix.assign(n + 1, 0);
        L.assign(n + 1, 0);
        multiset<int> cnt;
        int j = 0;
        for (int i = 0; i < n; i++) {
            cnt.insert(nums[i]);
            while (*cnt.rbegin() - *cnt.begin() > k) {
                cnt.erase(cnt.find(nums[j]));
                j++;
            }
            L[i + 1] = j;   
        }
        prefix[0] = solve(0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = (prefix[i - 1] + solve(i)) % mod;
        }
        return solve(n);
    }
};

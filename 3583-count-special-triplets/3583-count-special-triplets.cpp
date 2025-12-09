
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        unordered_map<int, int> l;
        unordered_map<int, int> r;
        for (int num : nums) {
            r[num]++;
        }
        long long count = 0;
        for (int j = 0; j < n; j++) {
            r[nums[j]]--;
            int target = nums[j] * 2;
            int left = l[target];
            int right = r[target];
            count = (count + 1LL * left * right) % MOD;
            l[nums[j]]++;
        }
        return count;
    }
};

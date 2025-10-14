class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<bool> inc(n, false);
        for (int i = 0; i + k <= n; i++) {
            bool ok = true;
            for (int j = i; j + 1 < i + k; j++) {
                if (nums[j] >= nums[j + 1]) {
                    ok = false;
                    break;
                }
            }
            inc[i] = ok;
        }
        for (int i = 0; i + 2 * k <= n; i++) {
            if (inc[i] && inc[i + k]) return true;
        }
        return false;
    }
};

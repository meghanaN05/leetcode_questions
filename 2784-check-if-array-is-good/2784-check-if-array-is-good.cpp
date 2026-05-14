class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(n + 1, 0);
        for (int x : nums) {
            if (x > n - 1) return false;
            a[x]++;
        }
        for (int i = 1; i < n; i++) {
            if (i == n - 1) {
                if (a[i] != 2) return false;
            } else {
                if (a[i] != 1) return false;
            }
        }
        return true;
    }
};
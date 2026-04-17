class Solution {
public:
    int r(int x) {
        int rr = 0;
        while (x > 0) {
            rr = rr * 10 + (x % 10);
            x /= 10;
        }
        return rr;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> pos;
        int ans = INT_MAX;
        for (int j = 0; j < nums.size(); j++) {
            if (pos.count(nums[j])) ans = min(ans, j - pos[nums[j]]);
            pos[r(nums[j])] = j;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
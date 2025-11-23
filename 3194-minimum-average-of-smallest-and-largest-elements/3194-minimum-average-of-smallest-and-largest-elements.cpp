class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1;
        double ans = 1e18; 
        while (l < r) {
            double avg = (nums[l] + nums[r]) / 2.0;
            ans = min(ans, avg);
            l++;
            r--;
        }
        return ans;
    }
};

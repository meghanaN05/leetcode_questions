class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax = 0, maxi = INT_MIN;
        for(auto c : nums)
            curMax = max(c, curMax + c),
            maxi = max(maxi, curMax);
        return maxi;
    }
};
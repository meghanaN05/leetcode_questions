class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total+= nums[i];
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += (nums[i] * i);
        }
        int maxi = cur;
        for (int i = n - 1; i > 0; i--) {
            int valueToBeAdded = total - nums[i];
            cur += valueToBeAdded;
            int valueToBeSubtracted = (nums[i] * (n - 1));
            cur -= valueToBeSubtracted;
            maxi= max(maxi, cur);
        }
        return maxi;
    }
};
class Solution {
public:
    int helper(vector<int>& nums, int left, int right) {
        if (left == right) {
            return nums[left];
        }
        return max(nums[left] - helper(nums, left + 1, right),
                   nums[right] - helper(nums, left, right - 1));
    }

    bool predictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1) >= 0;
    }
};

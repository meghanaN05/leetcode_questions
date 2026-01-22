class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int op = 0;
        while (!isSorted(nums)) {
            int mini = INT_MAX;
            int idx = 0;
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < mini) {
                    mini = sum;
                    idx = i;
                }
            }
            nums[idx] = mini;
            nums.erase(nums.begin() + idx + 1);
            op++;
        }

        return op;
    }
};

class Solution {
public:

  vector<vector<int>> combinations;
    vector<int> curr;
      void backtrack(int index, int n, int k, vector<int>& nums) {
        if (n == 0 && k == 0) {
            combinations.push_back(curr);
            return;
        }
        if (n < 0 || k < 0 || index >= nums.size()) return;

      
        backtrack(index + 1, n, k, nums);

        curr.push_back(nums[index]);
        backtrack(index + 1, n - nums[index], k - 1, nums);
        curr.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int> nums = {1,2,3,4,5,6,7,8,9};
        combinations.clear();
        curr.clear();
        backtrack(0, n, k, nums);
        return combinations;
    }
};
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
    
    int dfs(vector<int>& nums, int i, int curXor) {
        if (i == nums.size()) return curXor;
     
        return dfs(nums, i + 1, curXor ^ nums[i]) + dfs(nums, i + 1, curXor);
    }
};

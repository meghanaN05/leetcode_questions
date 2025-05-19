class Solution {
public:
    vector<vector<int>> results;  
    void helper(vector<int>& subsets, vector<int>& nums, int ind, int n) {
        if (ind >= n) {
            results.push_back(subsets); 
            return;
        }
        subsets.push_back(nums[ind]);
        helper(subsets, nums, ind + 1, n);
        subsets.pop_back();
        helper(subsets, nums, ind + 1, n);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        results.clear();  
        vector<int> subset;
        helper(subset, nums, 0, nums.size());
        return results;
    }
};

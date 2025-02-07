class Solution {
public:
    vector<vector<int>> results;

    void helper(vector<int>& subsets, vector<int>& nums, int ind) {
        if (ind >= nums.size()) {
            results.push_back(subsets);
            return;
        }

        // Include the current element
        subsets.push_back(nums[ind]);
        helper(subsets, nums, ind + 1);

        // Exclude the current element
        subsets.pop_back();
        
        // Skip duplicates
        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1]) {
            ind++;
        }
        
        helper(subsets, nums, ind + 1);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        results.clear();
        vector<int> subset;
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        helper(subset, nums, 0);
        return results;
    }
};

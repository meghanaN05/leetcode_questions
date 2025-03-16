class Solution {
public:
    vector<vector<int>> combinations;
    vector<int> Currsub;
    
    void backtrack(int index, int sum, int n, vector<int>& candidates, int target) {
        if (sum == target) {
            combinations.push_back(Currsub);
            return;
        }
        if (sum > target || index >= n) return;
        
        for (int i = index; i < n; ++i) {
            // Skip duplicates
            if (i > index && candidates[i] == candidates[i - 1]) continue;

            // Choose the current element
            Currsub.push_back(candidates[i]);
            backtrack(i + 1, sum + candidates[i], n, candidates, target);
            Currsub.pop_back(); // Backtrack
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        combinations.clear();
        Currsub.clear();
        backtrack(0, 0, n, candidates, target);
        return combinations;
    }
};

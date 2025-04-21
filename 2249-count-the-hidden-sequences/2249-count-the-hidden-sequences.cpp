class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long min_val = 0, max_val = 0, curr = 0;
        for (int diff : differences) {
            curr += diff;
            min_val = min(min_val, curr);
            max_val = max(max_val, curr);
        }
        long long min_start = lower - min_val;
        long long max_start = upper - max_val;
        long long ans = max_start - min_start + 1;
        return ans > 0 ? ans : 0;
    }
};

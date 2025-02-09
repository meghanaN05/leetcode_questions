class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long goodpairs = 0;
        int n = nums.size();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            long long key = nums[i] - i;
            goodpairs += freq[key];
            freq[key]++;
        }

        return (1LL * n * (n - 1)) / 2 - goodpairs; 
    }
};

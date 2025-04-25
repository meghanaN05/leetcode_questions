class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n = nums.size();
        long long result = 0;
        unordered_map<int, int> countMap;
        countMap[0] = 1;

        int prefix = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] % modulo == k) {
                prefix++;
            }
            int key = (prefix - k + modulo) % modulo;
            result += countMap[key];
            countMap[prefix % modulo]++;
        }

        return result;
    }
};

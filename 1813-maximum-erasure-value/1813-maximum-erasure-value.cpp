class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l = 0;
        unordered_set<int> seen;
        int maxsum = 0, sum = 0;

        for (int r = 0; r < nums.size(); r++) {
          
            while (seen.find(nums[r]) != seen.end()) {
                seen.erase(nums[l]);
                sum -= nums[l];
                l++;
            }

            
            seen.insert(nums[r]);
            sum += nums[r];
            maxsum = max(maxsum, sum);
        }

        return maxsum;
    }
};

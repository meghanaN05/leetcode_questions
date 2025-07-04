class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       unordered_map<int, int> lastSeenIndex;

        for (int i = 0; i < nums.size(); ++i) {
            if (lastSeenIndex.find(nums[i]) != lastSeenIndex.end()) {
                if (i - lastSeenIndex[nums[i]] <= k) {
                    return true;
                }
            }
            lastSeenIndex[nums[i]] = i;  
        }
        return false;
    }
};
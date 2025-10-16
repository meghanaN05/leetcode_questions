class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int r = (nums[i] % value + value) % value;
            mp[r]++;
        }
        int count = 0;
        while (true) {
            int r = count % value;
            if (mp[r] > 0) {
                mp[r]--;  
                count++;
            } else {
                break;     
            }
        }
        return count;
    }
};

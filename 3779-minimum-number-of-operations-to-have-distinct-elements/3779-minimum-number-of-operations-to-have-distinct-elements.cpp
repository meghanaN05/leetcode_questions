class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for (int x : nums) freq[x]++;
        int dupCount = 0;
        for (auto &p : freq) {
            if (p.second > 1) dupCount++;
        }
        int ops = 0;
        int i = 0;
        while (dupCount > 0 && i < n) {
            for (int k = 0; k < 3 && i < n; k++) {
                int val = nums[i];
                if (freq[val] == 2) dupCount--; 
                freq[val]--;
                if (freq[val] == 0) freq.erase(val);
                i++;
            }
            ops++;
        }

        return ops;
    }
};

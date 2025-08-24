class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, ans = 0, zeros = 0;
        for (int i= 0; i< nums.size(); i++) {
            if (nums[i] == 0) zeros++;
            while (zeros > 1) {
                if (nums[l] == 0) zeros--;
                l++;
            }

            ans = max(ans, i - l + 1);
        }
        return ans - 1; 
    }
};

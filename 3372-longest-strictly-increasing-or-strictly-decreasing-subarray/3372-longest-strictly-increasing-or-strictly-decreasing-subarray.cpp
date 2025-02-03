class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();  
        
        int maxLength = 1;  
        int inc_count = 1, dec_count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {       
                inc_count++;
                dec_count = 1;                
            } else if (nums[i] < nums[i - 1]) { 
                dec_count++;
                inc_count = 1;                 
            } else {                           
                inc_count = dec_count = 1;
            }
            maxLength = max(maxLength, max(inc_count, dec_count));
        }

        return maxLength;
    }
};

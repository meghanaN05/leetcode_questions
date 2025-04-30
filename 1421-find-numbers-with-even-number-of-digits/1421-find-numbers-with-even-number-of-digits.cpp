class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int number = 0;
        for (int i = 0; i < nums.size(); i++) {
            int count = 0; // reset count for each number
            int n = nums[i];
            while (n > 0) {
                n /= 10;
                count++;
            }
            if (count % 2 == 0) number++;
        }
        return number;
    }
};

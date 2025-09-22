class Solution {
public:
    int firstDigit(int x) {
        while (x >= 10) {
            x /= 10;
        }
        return x;
    }

    int countBeautifulPairs(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            int fd = firstDigit(nums[i]);   
            for (int j = i + 1; j < nums.size(); j++) {
                int ld = nums[j] % 10;      
                if (__gcd(fd, ld) == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

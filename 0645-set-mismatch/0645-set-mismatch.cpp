class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        long long n = nums.size();
        long long S = n * (n + 1) / 2;
        long long SQ = n * (n + 1) * (2 * n + 1) / 6;
        long long sum = 0, sqsum = 0;
        for (long long x : nums) {
            sum += x;
            sqsum += 1LL * x * x;
        }
        long long diff1 = sum - S;             
        long long diff2 = sqsum - SQ;          
        long long sum_xy = diff2 / diff1;     
        long long x = (diff1 + sum_xy) / 2;    
        long long y = x - diff1;              
        return {(int)x, (int)y};
    }
};

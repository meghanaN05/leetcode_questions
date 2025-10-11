class Solution {
public:
    int tribonacci(int n) {
       vector<int>memo(n+1,-1);
        return helper(n, memo);
    }
    
private:
    int helper(int n, vector<int>& memo) {
        if (memo[n]!=-1) {
            return memo[n];
        }
        
        int result;
        if (n == 0) {
            result = 0;
        } else if (n == 1 || n == 2) {
            result = 1;
        } else {
            result = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3, memo);
        }
        
        memo[n] = result;
        return result;
    }
};
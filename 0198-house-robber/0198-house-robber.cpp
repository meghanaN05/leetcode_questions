class Solution {
public:
//memorization code
   int solve(int i,vector<int>&memo,vector<int>& nums,int n){
    if(i>=n) return 0;
    if(memo[i]!=-1) return memo[i];
    int skip=solve(i+1,memo,nums,n);
    int take=nums[i]+solve(i+2,memo,nums,n);
     return memo[i]=max(skip,take);
   }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>memo(n,-1);
        return solve(0,memo,nums,n);
    }
};
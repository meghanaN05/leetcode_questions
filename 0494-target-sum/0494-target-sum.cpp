class Solution {
public:
  int cnt=0;
  int solve(int i,vector<int>& nums, int target,int sum){
    int n=nums.size();
    if(i==n) {
      if(target==sum) cnt++;
    }
    else{
      solve(i+1,nums,target,sum+nums[i]);
      solve(i+1,nums,target,sum-nums[i]);
      }
     return cnt;
  }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,nums,target,0);
    }
};
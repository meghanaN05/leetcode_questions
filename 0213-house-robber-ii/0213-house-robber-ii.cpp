class Solution {
public:
//space optimized solution
int solve(vector<int>& nums,int j,int n){
   int prev2=0;
    int prev=0;
      for(int i=j;i<=n;i++){
            int include=nums[i]+prev2;
            int exclude=prev;
            int curr=max(include,exclude);
            prev2=prev;
            prev=curr;
        }
        return prev;
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int c1=solve(nums,0,n-2);
        int c2=solve(nums,1,n-1);
          return max(c1,c2);
    }
};
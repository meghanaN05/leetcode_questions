class Solution {
public:
 //space optimization 
    int rob(vector<int>& nums) {
        int n=nums.size();
         if (n == 1) return nums[0];
        int prev2=nums[0];
        int prev=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
            int include=prev2+nums[i];
            int exclude=prev;
            int curr=max(include,exclude);
            prev2=prev;
            prev=curr;
        }
        return prev;

    }
};
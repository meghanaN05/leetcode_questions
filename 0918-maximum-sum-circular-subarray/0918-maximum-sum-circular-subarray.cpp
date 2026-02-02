class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN,curr_maxi=0;
        int mini=INT_MAX,curr_mini=0;
        for(int x:nums){
            sum+=x;
            curr_maxi=max(x,curr_maxi+x);
            maxi=max(maxi,curr_maxi);
             curr_mini=min(x,curr_mini+x);
            mini=min(mini,curr_mini);
        }
        if(sum==mini)
        return maxi;
        return max(maxi,sum-mini);
    }
};
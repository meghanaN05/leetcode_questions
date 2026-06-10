class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr=max(curr,curr+nums[i]);
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};
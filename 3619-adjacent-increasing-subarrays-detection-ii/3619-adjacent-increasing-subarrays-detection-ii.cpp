class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int k=0;
        int curr=1;
        int prev=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]) curr++;
            else{
                prev=curr;
                curr=1;
            }
            k=max(k,curr/2);
            k=max(k,min(curr,prev));

        }
        return k;
    }
};
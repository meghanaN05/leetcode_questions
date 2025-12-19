class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1) return 0;
        int maxi=*max_element(nums.begin(),nums.end())-k;
        int mini=*min_element(nums.begin(),nums.end())+k;
        int ans=maxi-mini;
        if(ans<0) return 0;
       return maxi-mini;
    }
};
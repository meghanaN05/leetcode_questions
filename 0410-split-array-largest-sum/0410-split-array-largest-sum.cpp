class Solution {
public:
bool possible(int mid,vector<int>& nums, int k){
    int cnt=1;
    int ans=0;
    for(int i=0;i<nums.size();i++){
        if(ans+nums[i]<=mid){
            ans+=nums[i];
        }
        else{
            ans=nums[i];
            cnt++;
        }
    }
    return cnt<=k;
}
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if((possible(mid,nums,k))){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
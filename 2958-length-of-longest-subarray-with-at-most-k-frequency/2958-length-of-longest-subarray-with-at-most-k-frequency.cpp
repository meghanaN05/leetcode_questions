class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l=0;
        unordered_map<int,int>mp;
        int maxi=1;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            while(mp[nums[i]]>k){
                mp[nums[l]]--;
                l++;
            }
            maxi=max(maxi,i-l+1);
        }
        return maxi;
    }
};
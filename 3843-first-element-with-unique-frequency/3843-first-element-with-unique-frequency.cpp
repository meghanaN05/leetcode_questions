class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        map<int,int>freqcount;
        for(auto it:mp){
           freqcount[it.second]++;
        }
        for(int x:nums){
            if(freqcount[mp[x]]==1)
            return x;
        }
         return -1;
    }
};
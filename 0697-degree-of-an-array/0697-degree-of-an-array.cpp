class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_map<int,int> first,last;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            if(first.find(nums[i])==first.end())
                first[nums[i]] = i;
            last[nums[i]] = i;
        }

        int mx = 0;
        for(auto it:mp){
            mx = max(mx,it.second);
        }

        int ans = nums.size();
        for(auto it:mp){
            if(it.second==mx){
                ans = min(ans,last[it.first]-first[it.first]+1);
            }
        }
        return ans;
    }
};

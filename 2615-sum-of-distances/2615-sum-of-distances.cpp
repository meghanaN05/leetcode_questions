class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        vector<long long>ans(n,0);
        for(int i=0;i<nums.size();i++){
                mp[nums[i]].push_back(i);
            }
        for(auto &it : mp) {
            vector<int> &group = it.second;
            long long total = accumulate(group.begin(), group.end(), 0LL);
            long long prefix = 0;
            int k = group.size();
            for(int i = 0; i < k; i++) {
                int idx = group[i];
                ans[idx] = total - 2 * prefix + (long long)idx * (2 * i - k);
                prefix += idx;
            }
        }

        return ans;
    }
};
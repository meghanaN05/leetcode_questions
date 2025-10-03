class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int total=pref[0];
        int n=pref.size();
        vector<int>ans(n);
        ans[0]=pref[0];
        for(int i=1;i<pref.size();i++){
            total=pref[i]^pref[i-1];
            ans[i]=total;
        }
        return ans;
    }
};
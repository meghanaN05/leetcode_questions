class Solution {
public:
int n;
int K;
int solve(vector<int>& energy, int i,vector<int>&t){
    if(i>=n) return 0;
    if(t[i]!=INT_MIN) return t[i];
    return t[i]=energy[i]+solve(energy,i+K,t);

}
    int maximumEnergy(vector<int>& energy, int k) {
        n=energy.size();
        K=k;
        int ans=INT_MIN;
        vector<int>t(n,INT_MIN);
        for(int i=0;i<n;i++)
        ans=max(ans,solve(energy,i,t));
        return ans;
    }
};
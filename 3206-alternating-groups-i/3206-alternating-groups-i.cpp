class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int cnt=0;
        int n=colors.size();
        vector<int>ans(n+2);
        for(int i=0;i<n;i++)
        ans[i]=colors[i];
        ans[n]=colors[0];
        ans[n+1]=colors[1];
        for(int i=0;i<ans.size()-2;i++){
            if(ans[i]==ans[i+2] && ans[i]!=ans[i+1])
            cnt++;
        }
        return cnt;
    }
};
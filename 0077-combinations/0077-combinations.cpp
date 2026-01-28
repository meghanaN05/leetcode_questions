class Solution {
public:
vector<int>ans;
vector<vector<int>>a;
 void backtrack(int i,int n,int k){
    if(ans.size()==k){
        a.push_back(ans);
        return;
    }
    for(int j=i;j<=n;j++){
        ans.push_back(j);
        backtrack(j+1,n,k);
        ans.pop_back();
    }
}
    vector<vector<int>> combine(int n, int k) {
        backtrack(1,n,k);
        return a;
    }
};
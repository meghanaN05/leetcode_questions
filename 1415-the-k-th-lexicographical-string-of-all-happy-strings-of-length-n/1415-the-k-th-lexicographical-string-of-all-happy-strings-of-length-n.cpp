class Solution {
public:
vector<string>ans;
void solve(int n,int k,string curr){
    if(curr.size()==n){
        ans.push_back(curr);
        return;
    }
    for(char ch='a';ch<='c';ch++){
        if(curr.size()>0 && curr.back()==ch) continue;
        solve(n,k,curr+ch);
    }

}
    string getHappyString(int n, int k) {
       solve(n,k,"");
       if(ans.size()<k) return "";
       return ans[k-1];
    }
};
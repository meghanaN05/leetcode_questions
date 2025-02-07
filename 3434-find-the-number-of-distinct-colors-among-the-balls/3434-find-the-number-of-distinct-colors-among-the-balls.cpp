class Solution {
public:
    static vector<int> queryResults(int limit, vector<vector<int>>& queries) {
       int n=queries.size();
        vector<int> ans(n, 0);
        unordered_map<int,int> mp;
        unordered_map<int,int> color;
        int i=0;
        for (auto& q: queries){
            int x=q[0], c=q[1];
            if (mp.count(x)>0){
                int c0=mp[x];
                if (--color[c0]==0) 
                    color.erase(c0);
            }
            mp[x]=c;
            color[c]++;
            ans[i++]=color.size();
        }
        return ans;
    }
};
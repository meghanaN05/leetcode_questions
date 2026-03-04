class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int cnt=0;
        vector<pair<int,int>> one;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    one.push_back({i,j});
                }
            }
        }
        for(int i=0;i<one.size();i++){
            int x = one[i].first;
            int y = one[i].second;
            bool ok = true;
            for(int j=0;j<one.size();j++){
                if(i!=j && (one[j].first==x || one[j].second==y)){
                    ok = false;
                    break;
                }
            }
            if(ok) cnt++;
        }
        return cnt;
    }
};
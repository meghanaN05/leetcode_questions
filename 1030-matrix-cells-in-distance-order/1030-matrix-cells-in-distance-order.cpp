class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        set<pair<int,pair<int,int>>>st;
        vector<vector<int>>ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int d=abs(j-cCenter)+abs(i-rCenter);
               st.insert({d,{i,j}});
            }
        }
       for (auto const& element : st) {
            ans.push_back({element.second.first, element.second.second});
        }
        return ans;
    }
};
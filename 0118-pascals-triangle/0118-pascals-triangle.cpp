class Solution {
public:
//using dp-1D
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res;
        vector<int>ans;
        for(int i=0;i<numRows;i++){
            vector<int>row(i+1,1);
            for(int j=1;j<i;j++){
                row[j]=ans[j-1]+ans[j];
            }
            res.push_back(row);
            ans=row;
        }
        return res;
    }
};
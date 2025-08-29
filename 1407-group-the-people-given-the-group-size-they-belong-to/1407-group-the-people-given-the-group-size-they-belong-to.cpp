class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int n = groupSizes.size();
        vector<vector<int>> grp(n+1);

        for (int i = 0; i < n; i++) {
            grp[groupSizes[i]].push_back(i);
            if (grp[groupSizes[i]].size() == groupSizes[i]) {
                ans.push_back(grp[groupSizes[i]]);
                grp[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};

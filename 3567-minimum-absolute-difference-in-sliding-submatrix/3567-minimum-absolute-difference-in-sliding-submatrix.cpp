class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1));
        for(int i = 0; i <= m - k; i++){
        for(int j = 0; j <= n - k; j++){
        set<int> st;
        for(int r = i; r < i + k; r++){
        for(int c = j; c < j + k; c++){
        st.insert(grid[r][c]);
            }
                }
        int mini = INT_MAX;
        vector<int> v(st.begin(), st.end());
        for(int t = 0; t < v.size() - 1; t++){
        mini = min(mini, v[t+1] - v[t]);
        }
        if(v.size() <= 1) mini = 0;
           res[i][j] = mini;
            }
        }
        return res;
    }
};
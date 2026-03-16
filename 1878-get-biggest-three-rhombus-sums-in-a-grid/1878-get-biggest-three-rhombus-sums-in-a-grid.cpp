class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        set<int> st;
        for(int i = 0; i < n; i++){
   for(int j = 0; j < m; j++){
    st.insert(grid[i][j]);
   for(int k = 1; i + 2*k < n && j - k >= 0 && j + k < m; k++){
       int sum = 0;
    for(int t = 0; t < k; t++)
  sum += grid[i + t][j + t];
for(int t = 0; t < k; t++)
   sum += grid[i + k + t][j + k - t];
      for(int t = 0; t < k; t++)
  sum += grid[i + 2*k - t][j - t];
 for(int t = 0; t < k; t++)
 sum += grid[i + k - t][j - k + t];
 st.insert(sum);
                }
            }
        }

        vector<int> ans(st.rbegin(), st.rend());

        if(ans.size() > 3) ans.resize(3);

        return ans;
    }
};
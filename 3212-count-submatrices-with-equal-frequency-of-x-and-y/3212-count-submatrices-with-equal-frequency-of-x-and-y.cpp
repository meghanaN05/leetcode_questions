class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
     int m = grid.size();
int n = grid[0].size();

vector<vector<int>> pref(m, vector<int>(n, 0));
vector<vector<int>> prefX(m, vector<int>(n, 0));

int count = 0;

for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {

        if(grid[i][j] == 'X') {
            pref[i][j] = 1;
            prefX[i][j] = 1;
        }
        else if(grid[i][j] == 'Y') {
            pref[i][j] = -1;
        }

        if(i > 0) {
            pref[i][j] += pref[i-1][j];
            prefX[i][j] += prefX[i-1][j];
        }

        if(j > 0) {
            pref[i][j] += pref[i][j-1];
            prefX[i][j] += prefX[i][j-1];
        }

        if(i > 0 && j > 0) {
            pref[i][j] -= pref[i-1][j-1];
            prefX[i][j] -= prefX[i-1][j-1];
        }

        if(pref[i][j] == 0 && prefX[i][j] > 0)
            count++;
    }
}

return count;
    }
};
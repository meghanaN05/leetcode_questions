class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {       int n=mat.size();
        if(mat==target) return true;
        int cnt=0;
        while(cnt<4){
            cnt++;
            if(mat==target) return true;
           for (int i = 0; i < n; i++)
             for (int j = i; j <n; j++)
                 swap(mat[i][j], mat[j][i]);
               reverse(mat.begin(), mat.end());
        }
           return false;
    }
};
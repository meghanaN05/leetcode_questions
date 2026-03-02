class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n,0);
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            int j=m-1;
            int count=0;
            while(j>=0 && grid[i][j]==0){
                j--;
                count++;
            }
            zeros[i]=count;
        }

        int ans=0;

        for(int i=0;i<n;i++){
            int needed = n - i - 1;  
            int pos = -1;
            for(int j=i;j<n;j++){
                if(zeros[j] >= needed){
                    pos = j;
                    break;
                }
            }

            if(pos == -1) return -1;
            for(int j=pos;j>i;j--){
                swap(zeros[j], zeros[j-1]);
                ans++;
            }
        }

        return ans;
    }
};
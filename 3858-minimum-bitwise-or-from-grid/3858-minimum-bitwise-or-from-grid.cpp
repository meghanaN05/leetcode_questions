class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans=0;
        int mini=0;
        for(int i=31;i>=0;i--){
            int a=mini|(1<<i);
            bool possible=true;
            for( int i=0;i<grid.size();i++){
                bool found=false;
                for(int j=0;j<grid[0].size();j++){
                    if((grid[i][j]&a)==0){
                        found=true;
                        break;
                    }
                }
                if(!found){
                    possible=false;
                    break;
                }
            }
            if(possible){
               mini=a;
            }
            else{
                ans|=(1<<i);
            }
        }
        return ans;
    }
};
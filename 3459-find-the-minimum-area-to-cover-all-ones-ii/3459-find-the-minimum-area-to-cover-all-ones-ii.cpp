class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = INT_MAX;

        auto area = [&](int r1,int r2,int c1,int c2){
            int minR=m, maxR=-1, minC=n, maxC=-1;
            for(int i=r1;i<=r2;i++){
                for(int j=c1;j<=c2;j++){
                    if(grid[i][j]==1){
                        minR = min(minR,i);
                        maxR = max(maxR,i);
                        minC = min(minC,j);
                        maxC = max(maxC,j);
                    }
                }
            }
            if(maxR==-1) return 0; 
            return (maxR-minR+1)*(maxC-minC+1);
        };

      
        for(int c1=0;c1<n-2;c1++){
            for(int c2=c1+1;c2<n-1;c2++){
                int a1=area(0,m-1,0,c1);
                int a2=area(0,m-1,c1+1,c2);
                int a3=area(0,m-1,c2+1,n-1);
                if(a1&&a2&&a3) ans=min(ans,a1+a2+a3);
            }
        }

       
        for(int r1=0;r1<m-2;r1++){
            for(int r2=r1+1;r2<m-1;r2++){
                int a1=area(0,r1,0,n-1);
                int a2=area(r1+1,r2,0,n-1);
                int a3=area(r2+1,m-1,0,n-1);
                if(a1&&a2&&a3) ans=min(ans,a1+a2+a3);
            }
        }

       
        for(int c=0;c<n-1;c++){
            for(int r=0;r<m-1;r++){
               
                int a1=area(0,r,0,c);
                int a2=area(r+1,m-1,0,c);
                int a3=area(0,m-1,c+1,n-1);
                if(a1&&a2&&a3) ans=min(ans,a1+a2+a3);

                a1=area(0,r,c+1,n-1);
                a2=area(r+1,m-1,c+1,n-1);
                a3=area(0,m-1,0,c);
                if(a1&&a2&&a3) ans=min(ans,a1+a2+a3);

             
                a1=area(0,r,0,c);
                a2=area(0,r,c+1,n-1);
                a3=area(r+1,m-1,0,n-1);
                if(a1&&a2&&a3) ans=min(ans,a1+a2+a3);
                a1=area(r+1,m-1,0,c);
                a2=area(r+1,m-1,c+1,n-1);
                a3=area(0,r,0,n-1);
                if(a1&&a2&&a3) ans=min(ans,a1+a2+a3);
            }
        }

        return ans;
    }
};

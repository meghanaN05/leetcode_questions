class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=start^goal;
        int cnt=0;
        // for(int i=0;i<31;i++){
        //     if(ans&(1<<i))
        //     cnt++;
        // }
        while(ans!=0){
       
         if(ans%2==1) cnt++;
          ans=ans/2;
        }
        return cnt;
    }
};
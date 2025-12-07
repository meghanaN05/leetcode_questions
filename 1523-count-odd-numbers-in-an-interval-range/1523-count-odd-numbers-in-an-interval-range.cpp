class Solution {
public:
    int countOdds(int low, int high) {
        int cnt=0;
         if(low%2==1 || high%2==1) cnt++;
    int range=high-low;
    cnt+=range/2;
    return cnt;
    }
};
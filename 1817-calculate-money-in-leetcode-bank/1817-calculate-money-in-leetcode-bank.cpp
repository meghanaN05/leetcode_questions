class Solution {
public:
    int totalMoney(int n) {
      int w=n/7;
      int r=n%7;
     int ans = 7*w*(w+7)/2 + r*(w+1) + r*(r-1)/2;
       return ans;
    }
};

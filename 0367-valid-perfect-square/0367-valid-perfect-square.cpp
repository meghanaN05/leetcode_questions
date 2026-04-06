class Solution {
public:
    bool isPerfectSquare(int num) {
        long long product=1;
       for(long long i=1;i*i<=num;i++){
          product=i*i;
          if(product==num) return true;
       }
       return false;
    }
};
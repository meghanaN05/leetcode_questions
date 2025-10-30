class Solution {
public:
    int smallestNumber(int n) {
         for(int i=0;i<=10;i++){
           int finalans=(pow(2,i))-1;
           if(finalans>=n)
            return finalans;
         }
        return -1;
        
        
    }
};
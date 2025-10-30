class Solution {
public:
    int numberOfSteps(int num) {
        int op=0;
        while(num>0){
            if(num%2==0){
              num=num/2;
              op++;
            } 
              else {
                num=num-1;
                op++;
              }
        }
        return op;
    }
};
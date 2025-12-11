class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            int number=i;
            int flag=true;
            while(number>0){
                int rem=number%10;
                if(rem==0){
                    flag=false;
                    break;
                }
                if( rem!=0 && i%rem!=0){
                    flag=false;
                    break;
                }
                number=number/10;
            }
         if(flag)   ans.push_back(i);
        }
        return ans;
    }
};
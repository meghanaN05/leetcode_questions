class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count_zero=0;
        int count_one=0;
        int a=0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){
                if(s[j]=='0'){
                    count_zero++;
                }
                else{
                    count_one++;
                }
                if(count_one<=k || count_zero<=k){
                    a++;
                }
            }
            count_zero=0;
            count_one=0;
        }
        return a;
    }
};
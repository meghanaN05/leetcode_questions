class Solution {
public:
    string toHex(int num) {
        string ans="0123456789abcdef";
        string s;
        unsigned int n=num;
        while(n>0){
            s+=ans[n%16];
            n/=16;
        }
        reverse(s.begin(),s.end());
        if(s=="") return "0";
        return s;

    }
};
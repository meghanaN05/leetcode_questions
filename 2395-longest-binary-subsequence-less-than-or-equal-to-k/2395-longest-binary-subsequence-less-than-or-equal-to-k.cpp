class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int length=0;
        int power=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                length++;
            }
            else if(power<=k){
                length++;
                k-=power;
            }
            if(power<=k){
                power=power*2;
            }
        }
        return length;
    }
};
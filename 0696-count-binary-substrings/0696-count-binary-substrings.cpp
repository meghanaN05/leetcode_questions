class Solution {
public:
    int countBinarySubstrings(string s) {
       int ans=0;
       for(int i=0;i<s.size();i++){
          int cnt1=0;
       int cnt0=0;
        for(int j=i;j<s.size();j++){
           if(s[j]=='0') cnt0++;
            if(s[j]=='1')  cnt1++;
            if(cnt1==cnt0){
                ans++;

            }

        }
       }
       return ans;
    }
};
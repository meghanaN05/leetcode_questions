class Solution {
public:
    int numSub(string s) {
        int one=0;
        int ans=0;
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1'){
                one++;
                ans+=one;
            }
           else {
            maxi=max(ans,maxi);
              one=0;  
            }
        }
        return ans;
    }
};
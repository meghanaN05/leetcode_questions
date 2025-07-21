class Solution {
public:
    string makeFancyString(string s) {
       string si="";
       int ans=1;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                ans++;
            }
            else{
                ans=1;
            }
             if(ans<3){
                si+=s[i-1];
             }
        }
        si+=s.back();
        return si;
    }
};
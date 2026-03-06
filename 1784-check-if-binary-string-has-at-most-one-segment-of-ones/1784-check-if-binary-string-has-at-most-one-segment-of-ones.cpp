class Solution {
public:
    bool checkOnesSegment(string s) {
        int i=0;
       while(i<s.size() && s[i]=='1'){
        i++;
       }
        for(int k=i;k<s.size();k++){
            if(s[k]=='1') return false;
        }
        return true;
    }
};
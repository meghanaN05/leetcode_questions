class Solution {
public:
    string pushDominoes(string s) {
        s='L'+s+'R';
        string result;
        int previous=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='.'){
                continue;
            }
            
            int span=i-previous-1;
            if(previous>0)
            result+=s[previous];
         if (s[previous] == s[i]) {
                result += string(span, s[previous]);
            }
            else if (s[previous] == 'L' && s[i] == 'R') {
                result += string(span, '.');
            }
            else { 
                result += string(span / 2, 'R')
                     + string(span % 2, '.')
                     + string(span/2,'L');
            }
            previous=i;
        }
        return result;
    }
};
class Solution {
public:
    string reverseWords(string s) {
        vector<string>result;
        string r="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
              result.push_back(r);
              r = "";
            }
            else{
                r+=s[i];
            }
        }
        result.push_back(r);
        string t="";
          for (int i = 0; i < result.size(); i++) {
            reverse(result[i].begin(), result[i].end()); 
            t += result[i];
            if (i < result.size() - 1) t += " "; 
        }
        return t;
    }
};
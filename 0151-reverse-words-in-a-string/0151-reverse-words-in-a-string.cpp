class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(), s.end());
        string result = "";
        string m = ""; 

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (!m.empty()) {        
                    reverse(m.begin(), m.end());
                    if (!result.empty()) result += " "; 
                    result += m;
                    m = "";
                }
            } else {
                m += s[i];
            }
        }

        if (!m.empty()) {  
            reverse(m.begin(), m.end());
            if (!result.empty()) result += " ";
            result += m;
        }

        return result;
    }
};

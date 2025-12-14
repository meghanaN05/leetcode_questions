class Solution {
public:
    string reverseWords(string s) {

        string s1 = "";
        int cntvowels = 0;
        int i = 0;
        for (; i < s.size() && s[i] != ' '; i++) {
            if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
              cntvowels++;
            }
                s1 += s[i];
        }
        if(s.size()==s1.size()) return s;
        vector<string> result;
        string next = "";

        for (i = i + 1; i < s.size(); i++) {
            if (s[i] == ' ') {
                result.push_back(next);
                next = "";
            } else {
                next += s[i];
            }
        }
        result.push_back(next);
        string r = s1;

        for (auto &a : result) {
            int v = 0;
            for (char c : a) {
                if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                    v++;
            }
            if (v == cntvowels) {
                reverse(a.begin(), a.end());
            }
            r += " " + a;
        }

        return r;
    }
};

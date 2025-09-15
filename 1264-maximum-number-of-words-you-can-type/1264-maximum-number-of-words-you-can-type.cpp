class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string> ans;
        string s = "";
        int a = 0;
        for (int i = 0; i < text.size(); i++) {
            if (text[i] == ' ') {
                ans.push_back(s);
                s = "";
            } else {
                s += text[i];
            }
        }
        ans.push_back(s);
        for (string &word : ans) {
            bool valid = true;
            for (char c : word) {
                if (brokenLetters.find(c) != string::npos) {
                    valid = false;
                    break;
                }
            }
            if (valid) a++;
        }

        return a;
    }
};

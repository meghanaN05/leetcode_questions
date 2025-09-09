class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string a = "qwertyuiop";
        string b = "asdfghjkl";
        string c = "zxcvbnm";
        
        vector<string> ans;
        
        for (string w : words) {
            int cnta = 0, cntb = 0, cntc = 0;
            string word = w;
            for (auto &ch : word) ch = tolower(ch);
            for (char ch : word) {
                if (a.find(ch) != string::npos) cnta++;
                if (b.find(ch) != string::npos) cntb++;
                if (c.find(ch) != string::npos) cntc++;
            }
            if (cnta == word.size() || cntb == word.size() || cntc == word.size()) {
                ans.push_back(w); 
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> ans;

    void backtrack(int i, string curr, string &s) {
        if (i == s.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(s[i]);
        backtrack(i + 1, curr, s);
        curr.pop_back();
        if (isalpha(s[i])) {
            curr.push_back(isupper(s[i]) ? tolower(s[i]) : toupper(s[i]));
            backtrack(i + 1, curr, s);
        }
    }

    vector<string> letterCasePermutation(string s) {
        backtrack(0, "", s);
        return ans;
    }
};

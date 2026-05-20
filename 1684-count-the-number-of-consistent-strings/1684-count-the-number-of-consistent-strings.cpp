class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> allowedChars(26, false);
        for(char ch : allowed) {
            allowedChars[ch - 'a'] = true;
        }
        int cnt = 0;
        for(string word : words) {
            bool ok = true;
            for(char ch : word) {
                if(!allowedChars[ch - 'a']) {
                    ok = false;
                    break;
                }
            }
            if(ok) cnt++;
        }
        return cnt;
    }
};
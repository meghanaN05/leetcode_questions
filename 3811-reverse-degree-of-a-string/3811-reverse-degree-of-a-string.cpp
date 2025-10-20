class Solution {
public:
    int reverseDegree(string s) {
        map<char, int> rev;  

        for (int i = 0; i < 26; i++) {
            char ch = 'a' + i;
            int val = 26 - i;  
            rev[ch] = val;
        }

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += (i+1) * rev[s[i]];
        }

        return ans;
    }
};

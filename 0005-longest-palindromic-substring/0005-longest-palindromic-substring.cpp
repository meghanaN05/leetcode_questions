class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        for (int ax = 0; ax < n; ax++) {
            int orb = 0;
            while (ax - orb >= 0 && ax + orb < n && s[ax - orb] == s[ax + orb]) {
                orb++;
            }
            orb--; 
            int len = 2 * orb + 1;
            if (len > ans.size()) {
                int st = ax - orb;
                ans = s.substr(st, len);
            }
        }
        for (int ax = 0; ax < n - 1; ax++) {
            int orb = 0;
            while (ax - orb >= 0 && ax + orb + 1 < n && s[ax - orb] == s[ax + orb + 1]) {
                orb++;
            }
            orb--;
            int len = 2 * (orb + 1);
            if (len > ans.size()) {
                int st = ax - orb;
                ans = s.substr(st, len);
            }
        }

        return ans;
    }
};

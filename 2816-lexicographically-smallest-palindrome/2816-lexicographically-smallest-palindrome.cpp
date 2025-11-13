class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while (l < r) {
            char mn = min(s[l], s[r]);
            s[l] = s[r] = mn;
            l++;
            r--;
        }
        return s;
    }
};

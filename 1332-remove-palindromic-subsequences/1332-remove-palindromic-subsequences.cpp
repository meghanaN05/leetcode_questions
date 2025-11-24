class Solution {
public:
    bool ispalindromic(string s){
        string original = s;
        reverse(s.begin(), s.end());
        return original == s;
    }

    int removePalindromeSub(string s) {
        if (s.size() == 0) return 0;   
        if (ispalindromic(s)) return 1; 
        return 2;                      
    }
};

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
               ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }

    string reverseVowels(string s) {
        int c = 0;
        int r = s.size() - 1;

        while (c < r) {
            if (!isVowel(s[c])) {
                c++; 
            } else if (!isVowel(s[r])) {
                r--; 
            } else {
                swap(s[c], s[r]);
                c++;
                r--;
            }
        }
        return s;
    }
};

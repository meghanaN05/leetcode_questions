class Solution {
public:
    int lengthOfLastWord(string s) {
        int x = 0;
        for (int i = s.length()-1; i >= 0; i--) {
            if (s[i] != ' ') {
                x++;
            } 
            if (s[i] == ' ' && x > 0) {
                break;
            }
        }
        return x;
    }
};
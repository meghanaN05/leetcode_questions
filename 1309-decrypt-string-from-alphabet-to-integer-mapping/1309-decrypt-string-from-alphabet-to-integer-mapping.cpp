class Solution {
public:
    string freqAlphabets(string s) {
        string result = "";
        int n = s.size();
        for (int i = 0; i < n; ) {
            if (i + 2 < n && s[i + 2] == '#') {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0'); 
                result.push_back('a' + num - 1);
                i += 3; 
            } else {
                int num = s[i] - '0'; 
                result.push_back('a' + num - 1);
                i++;
            }
        }
        return result;
    }
};

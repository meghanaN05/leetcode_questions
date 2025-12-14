class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        for(char c : s) {
            if(c == '1') ones++;
        }
        string result;
        result.append(ones - 1, '1'); 
        result.append(s.size() - ones, '0'); 
        result.push_back('1'); 
        return result;
    }
};

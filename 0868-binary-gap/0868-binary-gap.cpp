class Solution {
public:
    int binaryGap(int n) {
        int gap = 0;
        string s = bitset<32>(n).to_string();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {              
                for (int j = i + 1; j < s.size(); j++) {
                    if (s[j] == '1') {
                        gap = max(gap, j - i);  
                        break;                
                    }
                }
            }
        }
        return gap;
    }
};
class Solution {
public:
    int findComplement(int num) {
        string s = bitset<32>(num).to_string();
        s.erase(0, s.find_first_not_of('0'));
        for (int i = 0; i < s.size(); i++) {
            s[i] = (s[i] == '0' ? '1' : '0');
        }
        return stoi(s, nullptr, 2); 
    }
};

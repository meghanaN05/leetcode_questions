class Solution {
public:
    bool hasAlternatingBits(int n) {
         string s = bitset<32>(n).to_string();
        s.erase(0, s.find_first_not_of('0'));
        int cnt=0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='1' && s[i+1]=='1')  return false;
            else if(s[i]=='0' && s[i+1]=='0') return false;
        }
        return true;
    }
};
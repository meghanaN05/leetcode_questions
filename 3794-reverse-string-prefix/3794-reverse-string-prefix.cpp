class Solution {
public:
    string reversePrefix(string s, int k) {
        string res=s.substr(0,k);
        string r=s.substr(k,s.size());
        reverse(res.begin(),res.end());
        return res+r;
    }
};
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int remainder = s.size() % k;
        if (remainder > 0) {
            s += string(k - remainder, fill);  
        }
        vector<string> ans;
        for (int i = 0; i < s.size(); i += k) {
            ans.push_back(s.substr(i, k));
        }
        return ans;
    }
};

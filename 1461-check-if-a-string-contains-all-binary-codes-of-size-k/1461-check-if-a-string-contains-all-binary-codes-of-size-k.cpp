class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> ans;

        for(int i = 0; i + k <= s.size(); i++) {
            ans.insert(s.substr(i, k));
        }
        return ans.size() == (1 << k);
    }
};
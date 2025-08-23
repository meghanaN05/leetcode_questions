class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
           unordered_set<char> st(allowed.begin(), allowed.end());
    int ans = 0;
    for (auto &w : words) {
        bool ok = true;
        for (char c : w) {
            if (st.find(c) == st.end()) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    return ans;
    }
};
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        int n = s.size();
        vector<int> pos(26);
        for (int i = 0; i < n; i++) {
            pos[t[i]-'a'] = i;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(i - pos[s[i]-'a']);
        }
        return ans;
    }
};

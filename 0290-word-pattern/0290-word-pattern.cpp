class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_set<string> used;
        int spaces = count(s.begin(), s.end(), ' ');
       if (spaces + 1 != pattern.size()) return false;
        int index = 0;
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string res = "";
            while (index < s.size() && s[index] != ' ') {
                res += s[index];
                index++;
            }
            index++;
            if (mp.count(ch)) {
                if (mp[ch] != res) return false;
            } else {
                if (used.count(res)) return false;
                mp[ch] = res;
                used.insert(res);
            }
        }
        if (index < s.size()) return false;
        return true;
    }
};
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freqs(26, 0), freqt(26, 0);

        for (char c : s) freqs[c - 'a']++;
        for (char c : t) freqt[c - 'a']++;

        return freqs == freqt;
    }
};

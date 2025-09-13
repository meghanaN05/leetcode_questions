class Solution {
public:
    int maxFreqSum(string s) {
        int n = s.size();
        vector<int> freq_vowels(5, 0);   
        vector<int> freq_con(26, 0);   

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'a') freq_vowels[0]++;
            else if (ch == 'e') freq_vowels[1]++;
            else if (ch == 'i') freq_vowels[2]++;
            else if (ch == 'o') freq_vowels[3]++;
            else if (ch == 'u') freq_vowels[4]++;
            else freq_con[ch - 'a']++;
        }

        sort(freq_vowels.rbegin(), freq_vowels.rend());
        sort(freq_con.rbegin(), freq_con.rend());

        return freq_vowels[0] + freq_con[0];
    }
};

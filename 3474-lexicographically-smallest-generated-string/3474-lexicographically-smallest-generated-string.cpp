class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string s(n + m - 1, 'a');
        vector<int> fixed(n + m - 1, 0);
        for (int i = 0; i < n; i++) {
        if (str1[i] == 'T') {
         for (int j = 0; j < m; j++) {
        if (fixed[i + j] && s[i + j] != str2[j]) {
            return "";
                    }
        s[i + j] = str2[j];
        fixed[i + j] = 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool different = false;
                int idx = -1;

                for (int j = 0; j < m; j++) {
                    if (s[i + j] != str2[j]) {
                        different = true;
                    }
                    if (!fixed[i + j]) {
                        idx = i + j;
                    }
                }

                if (different) continue;
                if (idx != -1) {
                    s[idx] = (str2[idx - i] == 'a') ? 'b' : 'a';
                } else {
                    return "";
                }
            }
        }

        return s;
    }
};
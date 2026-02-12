class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int d = 0;
            int maxi= 0;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (freq[idx] == 0)
                    d++;
                freq[idx]++;
                maxi = max(maxi, freq[idx]);
                int len = j - i + 1;
                if (len == d * maxi)
                    res = max(res, len);
            }
        }

        return res;
    }
};

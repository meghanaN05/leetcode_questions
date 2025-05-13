class Solution {
public:
    const int MOD = 1e9 + 7;

    int lengthAfterTransformations(string s, int t) {
        vector<int> arr(26, 0);
        for (char ch : s) {
            arr[ch - 'a']++;
        }

        for (int i = 0; i < t; ++i) {
            vector<int> temp(26, 0);
            for (int j = 0; j < 26; ++j) {
                int freq = arr[j];
                if (j != 25) { 
                    temp[j + 1] = (temp[j + 1] + freq) % MOD;
                } else { 
                    temp[0] = (temp[0] + freq) % MOD; 
                    temp[1] = (temp[1] + freq) % MOD; 
                }
            }
            arr = temp;
        }

        int ans = 0;
        for (int count : arr) {
            ans = (ans + count) % MOD;
        }

        return ans;
    }
};

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxDiff = INT_MIN;

       
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 == 1) {  
                for (int j = 0; j < 26; ++j) {
                    if (freq[j] % 2 == 0 && freq[j] > 0) {  
                        maxDiff = max(maxDiff, freq[i] - freq[j]);
                    }
                }
            }
        }

        return maxDiff;
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
            if (s.empty() || t.empty()) return "";

    vector<int> freq(128, 0);
    for (char c : t)
        freq[c]++;

    int l = 0, count = t.size();
    int min_len = INT_MAX, start = 0;

    for (int i = 0; i < s.size(); i++) {
      
        if (freq[s[i]] > 0)
            count--;

        freq[s[i]]--;

       
        while (count == 0) {
           
            if (i - l + 1 < min_len) {
                min_len = i - l + 1;
                start = l;
            }

         
            freq[s[l]]++;
            if (freq[s[l]] > 0)
                count++;

            l++; 
        }
    }

    return min_len == INT_MAX ? "" : s.substr(start, min_len);

    }
};
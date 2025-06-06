class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;

        string result;
        stack<char> st;
        char min_char = 'a';

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            st.push(c);
            freq[c - 'a']--;

 
            while (min_char <= 'z' && freq[min_char - 'a'] == 0) {
                min_char++;
            }

    
            while (!st.empty() && st.top() <= min_char) {
                result += st.top();
                st.pop();
            }
        }

   
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }
};

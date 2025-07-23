class Solution {
public:
    int maximumGain(string s, int x, int y) {
       
        if (y > x) {
            swap(x, y);
            for (char& ch : s) {
                if (ch == 'a') ch = 'b';
                else if (ch == 'b') ch = 'a';
            }
        }

        int total = 0;
        stack<char> st;

        
        for (char ch : s) {
            if (!st.empty() && st.top() == 'a' && ch == 'b') {
                st.pop();
                total += x;
            } else {
                st.push(ch);
            }
        }

        
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        reverse(remaining.begin(), remaining.end());

     
        for (char ch : remaining) {
            if (!st.empty() && st.top() == 'b' && ch == 'a') {
                st.pop();
                total += y;
            } else {
                st.push(ch);
            }
        }

        return total;
    }
};

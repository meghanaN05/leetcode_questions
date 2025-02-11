class Solution {
public:
    bool check(stack<char>& st, string& part, int n) {
        stack<char> tempst = st;
        for (int idx = n - 1; idx >= 0; idx--) {
            if (tempst.top() != part[idx]) {
                return false;
            }
            tempst.pop();
        }
        return true;
    }

    string removeOccurrences(string s, string part) {
        int m = s.length();
        int n = part.length();
        stack<char> st;
        
    
        for (int i = 0; i < m; i++) {
            st.push(s[i]);

           
            if (st.size() >= n && check(st, part, n)) {
                for (int j = 0; j < n; j++) {
                    st.pop();
                }
            }
        }

       
        string result = "";
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};

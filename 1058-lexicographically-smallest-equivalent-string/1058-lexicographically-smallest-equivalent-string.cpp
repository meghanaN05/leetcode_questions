class Solution {
public:
    char BFSarray(unordered_map<char, vector<char>>& a, char ch) {
        vector<int> visited(26, 0);
        queue<char> q;
        q.push(ch);
        visited[ch - 'a'] = 1;
        char minchar = ch;

        while (!q.empty()) {
            char curr = q.front();
            q.pop();
            minchar = min(minchar, curr);
            for (char neighbor : a[curr]) {
                if (!visited[neighbor - 'a']) {
                    visited[neighbor - 'a'] = 1;
                    q.push(neighbor);
                }
            }
        }

        return minchar;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> a;

        for (int i = 0; i < s1.size(); ++i) {
            a[s1[i]].push_back(s2[i]);
            a[s2[i]].push_back(s1[i]);
        }

        string result;
        vector<char> minCharMap(26, 0);

        for (char ch : baseStr) {
            if (minCharMap[ch - 'a'] == 0) {
                char minch = BFSarray(a, ch);
                vector<int> visited(26, 0);
                queue<char> q;
                q.push(ch);
                visited[ch - 'a'] = 1;
                minCharMap[ch - 'a'] = minch;

                while (!q.empty()) {
                    char curr = q.front();
                    q.pop();
                    minCharMap[curr - 'a'] = minch;
                    for (char neighbor : a[curr]) {
                        if (!visited[neighbor - 'a']) {
                            visited[neighbor - 'a'] = 1;
                            q.push(neighbor);
                        }
                    }
                }
            }
            result.push_back(minCharMap[ch - 'a']);
        }

        return result;
    }
};

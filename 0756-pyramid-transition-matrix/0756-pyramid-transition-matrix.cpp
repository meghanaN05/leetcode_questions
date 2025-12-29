class Solution {
    int m[7][7];
    unordered_set<string> vis;
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        memset(m, 0, sizeof(m));
        for (string& s : allowed) m[s[0] - 'A'][s[1] - 'A'] |= 1 << (s[2] - 'A');
        return dfs(bottom, "");
    }
    bool dfs(string& cur, string nxt) {
        if (cur.size() == 1) return true;
        if (nxt.size() == cur.size() - 1) return vis.insert(nxt).second && dfs(nxt, "");
        int i = nxt.size(), bits = m[cur[i] - 'A'][cur[i + 1] - 'A'];
        for (int j = 0; j < 7; j++)
            if ((bits >> j) & 1) 
                if (dfs(cur, nxt + (char)('A' + j))) return true;
        return false;
    }
};

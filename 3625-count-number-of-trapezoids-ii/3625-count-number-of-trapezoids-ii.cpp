class Solution {
public:
    int countTrapezoids(vector<vector<int>>& p) {
        int n = p.size();
        unordered_map<float, vector<float>> s2i;
        unordered_map<int, vector<float>> m2s;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int x1 = p[i][0], y1 = p[i][1];
                int x2 = p[j][0], y2 = p[j][1];
                int dx = x2 - x1, dy = y2 - y1;
                float s, k;
                if(dx == 0) { s = 1e9 + 7; k = x1; }
                else { s = (float)dy / dx; k = (float)(y1 * dx - x1 * dy) / dx; }
                int m = (x1 + x2) * 10000 + (y1 + y2);
                s2i[s].push_back(k);
                m2s[m].push_back(s);
            }
        }
        for(auto &u : s2i) {
            if(u.second.size() <= 1) continue;
            map<float, int> mp;
            for(float k : u.second) mp[k]++;
            int prev = 0;
            for(auto &v : mp) { int c = v.second; ans += c * prev; prev += c; }
        }
        for(auto &u : m2s) {
            if(u.second.size() <= 1) continue;
            map<float, int> mp;
            for(float s : u.second) mp[s]++;
            int prev = 0;
            for(auto &v : mp) { int c = v.second; ans -= c * prev; prev += c; }
        }
        return ans;
    }
};

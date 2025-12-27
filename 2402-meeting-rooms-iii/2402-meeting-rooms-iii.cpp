class Solution {
public:
    typedef pair<long long,int> P;
    int mostBooked(int n, vector<vector<int>>& mt) {
        sort(mt.begin(), mt.end());
        vector<int> cnt(n, 0);
        priority_queue<P, vector<P>, greater<P>> used;
        priority_queue<int, vector<int>, greater<int>> free;

        for(int i = 0; i < n; i++) free.push(i);

        for(auto &v : mt) {
            int s = v[0], e = v[1];

            while(!used.empty() && used.top().first <= s) {
                free.push(used.top().second);
                used.pop();
            }

            if(!free.empty()) {
                int r = free.top(); free.pop();
                used.push({e, r});
                cnt[r]++;
            } else {
                auto [t, r] = used.top(); used.pop();
                used.push({t + (e - s), r});
                cnt[r]++;
            }
        }

        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(cnt[i] > cnt[ans]) ans = i;
        }
        return ans;
    }
};

class Solution {
    using p = pair<int,int>;
    struct C {
        bool operator()(const p& a, const p& b) const {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        }
    };
public:
    long long minimumCost(vector<int>& a, int k, int d) {
        int n = a.size();
        long long r = LLONG_MAX, s = a[0];
        int i = 1, j = 1;
         k--;
        set<p> sm;
        priority_queue<p, vector<p>, C> pq;
        while (i <= n - k) {
            bool del = false;
            while (sm.size() < k || j <= min(i + d, n - 1)) {
                p c = {INT_MAX, -1};
                if (j < n) c = {a[j], j};
                while (!pq.empty() && (j >= n || a[j] >= pq.top().first)) {
                    p t = pq.top(); pq.pop();
                    if (t.second < i) continue;
                    pq.push(c);
                    c = t;
                    break;
                }

                if (sm.size() < k) {
                    sm.insert(c);
                    s += c.first;
                } else {
                    auto it = prev(sm.end());
                    if (it->first >= c.first) {
                        p x = *it;
                        sm.erase(it);
                        sm.insert(c);
                        s -= (x.first - c.first);
                        if (x.second != i) pq.push(x);
                        else del = true;
                    } else {
                        pq.push(c);
                    }
                }
                j++;
            }
            r = min(r, s);
            if (!del) {
                if (sm.erase({a[i], i})) s -= a[i];
            }
            i++;
        }
        return r;
    }
};

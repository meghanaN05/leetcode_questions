class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            long long x = points[i][0];
            long long y = points[i][1];
            long long dist = x * x + y * y; 
            pq.push({dist, {x, y}});
            if (pq.size() > k) {
                pq.pop(); 
            }
        }
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};

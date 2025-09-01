class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();

        priority_queue<pair<double,int>> pq;
        for (int i = 0; i < n; i++) {
            double cur = (double)classes[i][0] / classes[i][1];
            double newv = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            pq.push({newv - cur, i});
        }

        while (extraStudents--) {
            auto curr = pq.top();
            pq.pop();
            int idx = curr.second;
            classes[idx][0]++;
            classes[idx][1]++;
            double curr_PR = (double)classes[idx][0] / classes[idx][1];
            double new_PR = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
            pq.push({new_PR - curr_PR, idx});
        }

        double result = 0.0;
        for (int i = 0; i < n; i++) {
            result += (double)classes[i][0] / classes[i][1];
        }
        return result / n;
    }
};

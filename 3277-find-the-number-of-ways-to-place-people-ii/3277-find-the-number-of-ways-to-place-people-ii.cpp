class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int result = 0;
        sort(points.begin(), points.end(), [](const auto &a, const auto &b){
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] > b[1];
        });

        for (int i = 0; i < n; i++) {
            int y1 = points[i][1];
            int maxi_y = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int y2 = points[j][1];
                if (y2 <= y1) {                 
                    if (maxi_y < y2) result++;  
                    maxi_y = max(maxi_y, y2);
                }
                
            }
        }
        return result;
    }
};

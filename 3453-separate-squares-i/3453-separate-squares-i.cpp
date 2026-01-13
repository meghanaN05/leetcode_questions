class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double maxi= 0, totalarea = 0;
        for (auto& sq : squares) {
            int y = sq[1], l = sq[2];
            totalarea += (double)l * l;
            maxi = max(maxi, (double)(y + l));
        }

        auto check = [&](double limit_y) -> bool {
            double area = 0;
            for (auto& sq : squares) {
                int y = sq[1], l = sq[2];
                if (y < limit_y) {
                    area += l * min(limit_y - y, (double)l);
                }
            }
            return area >= totalarea / 2;
        };

        double l = 0, h = maxi;
        double eps = 1e-5;
        while (abs(h - l) > eps) {
            double mid = (h + l) / 2;
            if (check(mid)) {
                h= mid;
            } else {
                l= mid;
            }
        }
        return h;
    }
};
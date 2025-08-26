class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxiDiagonal = 0;
        int maxiArea = 0;

        for (int i = 0; i < dimensions.size(); i++) {
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            int diagSq = l * l + w * w;  
            int area = l * w;

            if (diagSq > maxiDiagonal || (diagSq == maxiDiagonal && area > maxiArea)) {
                maxiDiagonal = diagSq;
                maxiArea = area;
            }
        }
        return maxiArea;
    }
};

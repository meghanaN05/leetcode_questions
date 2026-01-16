class Solution {
public:
    int longestConsecutive(vector<int>& bars) {
        sort(bars.begin(), bars.end());
        int maxLen = 1, curr = 1;
        for (int i = 1; i < bars.size(); i++) {
            if (bars[i] == bars[i - 1] + 1) {
                curr++;
            } else {
                curr = 1;
            }
            maxLen = max(maxLen, curr);
        }
        return maxLen;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = longestConsecutive(hBars);
        int v = longestConsecutive(vBars);
        int side = min(h + 1, v + 1);
        return side * side;
    }
};

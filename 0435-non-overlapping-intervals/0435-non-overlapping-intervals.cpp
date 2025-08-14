class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int count = 0; 
        int end = INT_MIN;
        for (auto &it : intervals) {
            if (it[0] >= end) {
                count++;
                end = it[1];
            }
        }
        return intervals.size() - count;
    }
};

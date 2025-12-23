class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& events, int i, int count) {
        if (i >= events.size() || count == 2)
        return 0;
        if (dp[i][count] != -1)
        return dp[i][count];
        int nottake = solve(events, i + 1, count);
        int l = i + 1, r = events.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (events[mid][0] > events[i][1])
                r = mid;
            else
                l = mid + 1;
        }
        int take = events[i][2] + solve(events, l, count + 1);
        return dp[i][count] = max(take, nottake);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        dp.assign(events.size(), vector<int>(3, -1));
        return solve(events, 0, 0);
    }
};

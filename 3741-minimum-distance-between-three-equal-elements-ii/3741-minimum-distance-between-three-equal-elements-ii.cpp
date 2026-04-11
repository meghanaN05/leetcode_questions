class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++) arr.push_back({nums[i], i});
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        for (int i = 0; i + 2 < n; i++) {
            if (arr[i].first == arr[i + 1].first && arr[i + 1].first == arr[i + 2].first) {
                int x = arr[i].second;
                int y = arr[i + 1].second;
                int z = arr[i + 2].second;
                int dist = abs(x - y) + abs(y - z) + abs(z - x);
                ans = min(ans, dist);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
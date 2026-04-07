class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        for (auto &log : logs) {
            mp[log[0]].insert(log[1]);
        }
        vector<int> ans(k, 0);
        for (auto &it : mp) {
            int cnt = it.second.size();
            ans[cnt - 1]++;
        }
        return ans;
    }
};
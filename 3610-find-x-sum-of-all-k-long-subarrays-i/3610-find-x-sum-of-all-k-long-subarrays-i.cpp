class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans;
        
        for (int i = 0; i + k <= n; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++)
                freq[nums[j]]++;
            vector<pair<int, int>> vec(freq.begin(), freq.end());
            sort(vec.begin(), vec.end(), [](auto &a, auto &b) {
                if (a.second == b.second)
                    return a.first > b.first;
                return a.second > b.second;
            });
            int sum = 0;
            for (int j = 0; j < min(x, (int)vec.size()); j++)
                sum += vec[j].first * vec[j].second;
            ans.push_back(sum);
        }
        return ans;
    }
};

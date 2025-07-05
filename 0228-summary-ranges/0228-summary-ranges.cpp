class Solution {
public:
    vector<string> summaryRanges(vector<int>& num) {
        vector<string> ans;
        int n = num.size();
        if (n == 0) return ans;

        int start = 0;

        for (int i = 1; i < n; ++i) {
            if (num[i] != num[i - 1] + 1) {
                if (start == i - 1)
                    ans.push_back(to_string(num[start]));
                else
                    ans.push_back(to_string(num[start]) + "->" + to_string(num[i - 1]));
                start = i;
            }
        }

        // Handle the last range
        if (start == n - 1)
            ans.push_back(to_string(num[start]));
        else
            ans.push_back(to_string(num[start]) + "->" + to_string(num[n - 1]));

        return ans;
    }
};

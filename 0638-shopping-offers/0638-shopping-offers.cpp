class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        unordered_map<string, int> memo;
        return shopping(price, special, needs, memo);
    }

    int shopping(vector<int>& price, vector<vector<int>>& special, vector<int> needs, unordered_map<string, int>& memo) {
        string key = encode(needs);
        if (memo.count(key)) return memo[key];

        int res = dot(price, needs);
        for (auto& s : special) {
            vector<int> clone = needs;
            int j = 0;
            for (; j < needs.size(); ++j) {
                if (clone[j] < s[j]) break;
                clone[j] -= s[j];
            }
            if (j == needs.size()) {
                res = min(res, s[j] + shopping(price, special, clone, memo));
            }
        }
        memo[key] = res;
        return res;
    }

    int dot(vector<int>& a, vector<int>& b) {
        int sum = 0;
        for (int i = 0; i < a.size(); ++i) {
            sum += a[i] * b[i];
        }
        return sum;
    }

    // Helper to encode the needs vector as a string key for memoization
    string encode(const vector<int>& needs) {
        string key;
        for (int n : needs) {
            key += to_string(n) + ",";
        }
        return key;
    }
};

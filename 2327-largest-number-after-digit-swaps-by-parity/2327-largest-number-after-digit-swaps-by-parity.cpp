class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> even, odd;

        for (char c : s) {
            int d = c - '0';
            (d % 2 ? odd : even).push_back(d);
        }

        sort(odd.rbegin(), odd.rend());
        sort(even.rbegin(), even.rend());

        int oi = 0, ei = 0;
        int ans = 0;

        for (char c : s) {
            int d = c - '0';
            ans = ans * 10 + (d % 2 ? odd[oi++] : even[ei++]);
        }

        return ans;
    }
};
class Solution {
public:
    vector<string> ans;

    void backtarck(string num, int target, int index, long long currval, long long preval, string s) {
        if (index == num.size()) {
            if (currval == target) {
                ans.push_back(s);
            }
            return;
        }

        for (int i = index; i < num.size(); i++) {
            if (i != index && num[index] == '0') break;

            string numstr = num.substr(index, i - index + 1);
            long long n = stoll(numstr);

            if (index == 0) {
                backtarck(num, target, i + 1, n, n, numstr);
            } else {
                backtarck(num, target, i + 1, currval + n, n, s + "+" + numstr);
                backtarck(num, target, i + 1, currval - n, -n, s + "-" + numstr);
                backtarck(num, target, i + 1, currval - preval + preval * n, preval * n, s + "*" + numstr);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        backtarck(num, target, 0, 0, 0, "");
        return ans;
    }
};

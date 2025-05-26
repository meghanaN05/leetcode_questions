class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; max(i, j) <= n - i - j; ++j) {
                string a = num.substr(0, i);
                string b = num.substr(i, j);
                
                if ((a.size() > 1 && a[0] == '0') || (b.size() > 1 && b[0] == '0'))
                    continue;
                
                if (isValid(a, b, num.substr(i + j)))
                    return true;
            }
        }
        return false;
    }

    bool isValid(string a, string b, string remaining) {
        while (!remaining.empty()) {
            string sum = addStrings(a, b);
            if (remaining.substr(0, sum.size()) != sum)
                return false;
            remaining = remaining.substr(sum.size());
            a = b;
            b = sum;
        }
        return true;
    }

    string addStrings(string num1, string num2) {
        string res;
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            res.push_back((sum % 10) + '0');
            carry = sum / 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution {
public:
    string binary(int num) {
        string s = "";
        if (num == 0) return "0";
        while (num > 0) {
            s += (num % 2 == 0 ? '0' : '1');
            num /= 2;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    int hammingDistance(int x, int y) {
        string a = binary(x);
        string b = binary(y);
        while (a.size() < b.size()) a = '0' + a;
        while (b.size() < a.size()) b = '0' + b;

        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) cnt++;
        }
        return cnt;
    }
};

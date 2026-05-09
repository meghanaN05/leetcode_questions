class Solution {
public:
    int minFlips(string s) {
        int N = s.length();
        if (N == 0) return 0;
        int z = 0;
        for (char c : s) {
            if (c == '0') z++;
        }
        int o = N - z;
        if (s.front() == '1' && s.back() == '1') {
            o--;
        }
        if (z < o - 1) {
            return max(z, 0);
        } else {
            return max(0, o - 1);

        }
    }
};
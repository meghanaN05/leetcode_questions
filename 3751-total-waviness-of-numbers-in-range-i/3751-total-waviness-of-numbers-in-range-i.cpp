class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for (int num = num1; num <=num2; num++) {
            string s = to_string(num);
            for (int i = 0; i + 2 < s.size(); i++) {
                int c1 = s[i] - '0';
                int c2 = s[i + 1] - '0';
                int c3 = s[i + 2] - '0';
                if ((c2 < c1 && c2 < c3) || 
                    (c2 > c1 && c2 > c3)) {
                    count++;
                }
            }
        }
        return count;
    }
};

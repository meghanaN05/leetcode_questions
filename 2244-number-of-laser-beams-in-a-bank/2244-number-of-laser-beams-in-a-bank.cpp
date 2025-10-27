class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int p = 0, t = 0;

        for (string &row : bank) {
            int devices = count(row.begin(), row.end(), '1');
            if (devices > 0) {
                t += p * devices;
                p = devices;
            }
        }

        return t;
    }
};
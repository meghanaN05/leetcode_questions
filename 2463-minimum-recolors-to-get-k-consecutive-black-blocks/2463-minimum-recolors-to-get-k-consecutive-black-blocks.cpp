class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int op = 0;
        int black = 0;
        int mini = INT_MAX;

        for (int i = 0; i <= blocks.size() - k; i++) {
            op = 0;
            black = 0;

            for (int j = i; j < i + k; j++) { 
                if (blocks[j] == 'W') {
                    op++;
                } else {
                    black++;
                }
            }

            mini = min(mini, op);
        }

        return mini;
    }
};

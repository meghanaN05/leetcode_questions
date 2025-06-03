class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (sum % 4 != 0) return false;
        int target = sum / 4;

        sort(matchsticks.rbegin(), matchsticks.rend()); // Sort in descending order
        vector<int> sides(4, 0); // 4 sides of the square

        return dfs(matchsticks, 0, sides, target);
    }

    bool dfs(vector<int>& matchsticks, int index, vector<int>& sides, int target) {
        if (index == matchsticks.size()) {
            return sides[0] == target && sides[1] == target &&
                   sides[2] == target && sides[3] == target;
        }

        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchsticks[index] > target) continue;
            sides[i] += matchsticks[index];
            if (dfs(matchsticks, index + 1, sides, target)) return true;
            sides[i] -= matchsticks[index];
            // Optimization: if one side didn't work, no need to try the same for empty sides
            if (sides[i] == 0) break;
        }
        return false;
    }
};

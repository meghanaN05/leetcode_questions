class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int, set<int>> row, col;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            row[x].insert(y);
            col[y].insert(x);
        }
        int ans = 0;
        for (auto& b : buildings) {
            int x = b[0], y = b[1];
            auto itRow = row[x].lower_bound(y);
            bool hasLeft = (itRow != row[x].begin());
            bool hasRight = (++itRow != row[x].end());
            auto itCol = col[y].lower_bound(x);
            bool hasAbove = (itCol != col[y].begin());
            bool hasBelow = (++itCol != col[y].end());
            if (hasLeft && hasRight && hasAbove && hasBelow) {
                ans++;
            }
        }

        return ans;
    }
};

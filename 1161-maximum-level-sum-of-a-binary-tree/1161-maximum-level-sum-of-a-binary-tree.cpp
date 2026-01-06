class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        if (!root) return 0;
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            vector<int> level;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        int maxi = INT_MIN;
        int index = 1;

        for (int i = 0; i < res.size(); i++) {
            int sum = 0;
            for (int j = 0; j < res[i].size(); j++) {
                sum += res[i][j];
            }
            if (sum > maxi) {
                maxi = sum;
                index = i + 1;  
            }
        }
        return index;
    }
};

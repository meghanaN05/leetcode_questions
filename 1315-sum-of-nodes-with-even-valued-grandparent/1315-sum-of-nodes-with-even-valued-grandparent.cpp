class Solution {
public:
    int dfs(TreeNode* root, TreeNode* parent, TreeNode* grandparent) {
        if (!root) return 0;
        int sum = 0;
        if (grandparent && grandparent->val % 2 == 0) {
            sum += root->val;
        }
        sum += dfs(root->left, root, parent);
        sum += dfs(root->right, root, parent);
        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};

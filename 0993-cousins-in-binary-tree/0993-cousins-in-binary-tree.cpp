class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool isSibling = false; 
        while (!q.empty()) {
            vector<int> depth;
            for (int i = 0; i < q.size(); i++) {
                TreeNode* r = q.front();
                q.pop();
                if (r->left && r->right) {
                    if ((r->left->val == x && r->right->val == y) ||
                        (r->left->val == y && r->right->val == x)) {
                        isSibling = true;
                    }
                }

                if (r->left != NULL) q.push(r->left);
                if (r->right != NULL) q.push(r->right);

                depth.push_back(r->val);
            }
            ans.push_back(depth);
        }
        int ix = -1, iy = -1;
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if (ans[i][j] == x) ix = i;
                if (ans[i][j] == y) iy = i;
            }
        }
        if (ix == iy && !isSibling) return true;
        return false;
    }
};
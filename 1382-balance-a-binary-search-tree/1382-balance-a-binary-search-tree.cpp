/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  vector<TreeNode*> arr;
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    TreeNode* dfs(int l,int r){
        if(l>r) return NULL;
        int m=(l+r)/2;
        TreeNode* left=dfs(l,m-1);
        TreeNode* right=dfs(m+1,r);
        arr[m]->left=left;
        arr[m]->right=right;
        return arr[m];
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return dfs(0,arr.size()-1);
    }
};
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        ans.push_back(root->val);
        vector<int>l=preorderTraversal(root->left);
        ans.insert(ans.end(),l.begin(),l.end());
         vector<int>r=preorderTraversal(root->right);
        ans.insert(ans.end(),r.begin(),r.end());
        return ans;
    }
};
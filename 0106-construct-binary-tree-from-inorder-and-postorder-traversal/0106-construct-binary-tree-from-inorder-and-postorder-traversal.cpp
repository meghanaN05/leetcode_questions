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
 TreeNode *build( vector<int> &inorder, int instart, int inend, vector<int> &postorder, int poststart, int postend,map<int, int> &mp)
  {
    if (poststart > postend || instart > inend)
      return NULL;
    TreeNode *root = new TreeNode(postorder[postend]);
    int inroot = mp[postorder[postend]];
    int numsleft = inroot - instart;
    root->left = build( inorder, instart, inroot,postorder, poststart , poststart + numsleft-1, mp);
    root->right = build( inorder, inroot+1, inend,postorder, poststart+numsleft , postend-1, mp);
    return root;
  }
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
      mp[inorder[i]] = i;
    }
    TreeNode *root = build(inorder, 0, inorder.size() - 1,postorder, 0, postorder.size() - 1, mp);
    return root;
    }
};
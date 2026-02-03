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
int sum=0;
int maxi=0;
void dfs(TreeNode* root,int depth){
    if(!root) return;
    if(depth>maxi){
        maxi=depth;
        sum=root->val;
    }
   else if(depth==maxi) sum+=root->val;
    dfs(root->left,depth+1);
    dfs(root->right,depth+1);

}
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL) return 0;
        dfs(root,0);
        return sum;
    }
};
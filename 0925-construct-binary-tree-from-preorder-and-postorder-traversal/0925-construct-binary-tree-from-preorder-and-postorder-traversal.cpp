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
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post) {
        int n = pre.size();
        int preIndex = 0;
        unordered_map<int, int> postIndex;
        for (int i = 0; i < n; i++) postIndex[post[i]] = i;
        
        return construct(pre, post, preIndex, 0, n - 1, n, postIndex);
    }
    TreeNode* construct(vector<int> &pre, vector<int> &post, int &preIndex, int l, int r, int n, unordered_map<int, int> &postIndex) {
        if (preIndex >= n || l > r) return NULL;
        
        TreeNode* root = new TreeNode(pre[preIndex]);
        preIndex++;
        if (l == r || preIndex >= n) return root;
        int leftVal = pre[preIndex];
        int mid = postIndex[leftVal];
        root->left = construct(pre, post, preIndex, l, mid, n, postIndex);
        root->right = construct(pre, post, preIndex, mid + 1, r - 1, n, postIndex);
        
        return root;
    }
};

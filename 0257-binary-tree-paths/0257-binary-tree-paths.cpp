// #include <bits/stdc++.h>
// using namespace std;

// // TreeNode definition
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    void dfs(TreeNode* root, string path, vector<string>& result) {
        if (!root) return;
        if (!path.empty()) {
            path += "->";
        }
        path += to_string(root->val);
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }

        dfs(root->left, path, result);
        dfs(root->right, path, result);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        dfs(root, "", result);
        return result;
    }
};

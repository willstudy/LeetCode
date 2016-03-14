/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string toString(int n) {
    stringstream ss;
    string str;
    ss << n;
    ss >> str;
    return str;
}
void DFS(TreeNode* root, vector<string>& vec, string str) {
    if (root->left == NULL && root->right == NULL) {
        vec.push_back(str + toString(root->val));
    }
    if (root->left != NULL) {
        DFS(root->left, vec, str + toString(root->val) + "->");
    }
    if (root->right != NULL) {
        DFS(root->right, vec, str + toString(root->val) + "->");
    }
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    if (root == NULL)
        return res;
    DFS(root, res, "");
    return res;
}
};

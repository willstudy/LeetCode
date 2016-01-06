/*
Invert a binary tree.
     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if( root->left == NULL && root->right == NULL ) return root;

    if( root->left )
    {
        TreeNode * p_left = root->left;

        root->left = root->right;
        if( root->right )
        {
            root->right = p;
        }
        else
        {
            root->right = NULL;
        }
    }
    else
    {

    }
}

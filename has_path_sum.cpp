/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path
such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
        if (root->val == sum && root->left ==  NULL && root->right == NULL) return true;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

/*
 * 二叉树的非递归遍历
 */

 bool hasPathSum( TreeNode * root, int sum )
 {
   stack<TreeNode *> S;
   TreeNode * node = root;
   TreeNode * pre = NULL;
   int total = 0;

   while( node || !S.empty() )
   {
     while( node )    // 一直遍历左子树
     {
       total += node->val;
       S.push(node);
       node = node->left;
     }

     node = S.top();

     if( node->left == NULL && node->right == NULL && total == sum ) return true;
     if( node->right && pre != node->right ) node = node->right;
     else
     {
       pre = node;
       S.pop();
       total -= node->val;
       node = NULL;
     }
   }
 }

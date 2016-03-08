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
     TreeNode* invertTree(TreeNode* root) {

         queue<TreeNode *> Q;

         if( root == NULL ) return NULL;

         Q.push( root );

         while( ! Q.empty() )
         {
             TreeNode * p = Q.front();
             TreeNode * left = p->left;
             TreeNode * right = p->right;

             if( left == NULL && right == NULL )
             {
                 Q.pop();
                 continue;
             }

             if( left != NULL && right != NULL )
             {
                 p->left = right;
                 p->right = left;

                 Q.push(left);
                 Q.push(right);
             }
             else if( left == NULL )  // left = NULL , right != NULL
             {
                  p->left = right;
                  p->right = NULL;
                  Q.push(right);
             }
             else  // right = NULL, left != NULL
             {
                 p->right = left;
                 p->left = NULL;
                 Q.push(left);
             }

             Q.pop();
         }

         return root;
     }
 };

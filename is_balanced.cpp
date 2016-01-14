/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a
binary tree in which the depth of the two subtrees of every node never
differ by more than 1.
*/
class Solution {
public:
  int getHeight( TreeNode * node )
  {
      if( node == NULL ) return 0;

      int left_height = getHeight( node->left );
      int right_height = getHeight( node->right );

      return max( left_height, right_height ) + 1;
  }
  bool isBalanced(TreeNode* root) {
      if( root == NULL ) return true;

      queue<TreeNode *> Q;

      Q.push( root );

      while( !Q.empty() )
      {
          TreeNode * node = Q.front();

          int left_height = 0;
          int right_height = 0;

          if( node->left )
          {
              left_height = getHeight( node->left );
              Q.push( node->left );

          }
          if( node->right )
          {
              right_height = getHeight( node->right );
              Q.push( node->right );
          }

          int diff = left_height - right_height;

          if( abs( diff ) > 1 ) return false;

          Q.pop();

      }
      return true;
  }
};

class Solution {
public:
  int depth (TreeNode *root) {
      if (root == NULL) return 0;
      return max (depth(root -> left), depth (root -> right)) + 1;
  }

  bool isBalanced (TreeNode *root) {
      if (root == NULL) return true;

      int left=depth(root->left);
      int right=depth(root->right);

      return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
  }
};

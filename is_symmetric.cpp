/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
  1
 / \
2   2
 \   \
  3    3
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
/*
 * 注意压队列的顺序
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if( root == NULL ) return true;

        queue<TreeNode *> Q;

        Q.push( root->left );
        Q.push( root->right );

        while( !Q.empty() )
        {
            TreeNode * node1 = Q.front();
            Q.pop();
            TreeNode * node2 = Q.front();
            Q.pop();

            if( !node1 && node2 ) return false;
            if( !node2 && node1 ) return false;
            if( node1 && node2 )
            {
                if( node1->val != node2->val ) return false;

                Q.push( node1->left );
                Q.push( node2->right );
                Q.push( node1->right );
                Q.push( node2->left );
            }
        }
        return true;
    }
};

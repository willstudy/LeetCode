/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path
from the root node down to the farthest leaf node.
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
    int maxDepth(TreeNode* root) {
        if ( root == NULL ) return 0;

        queue<TreeNode *> Q;
        int maxDepth = 0;

        Q.push(root);

        while( ! Q.empty() )
        {
            ++maxDepth;

            for( int i = 0, n = Q.size(); i < n; i++ )
            {
                TreeNode * q = Q.front();
                Q.pop();

                if( q->left ) Q.push(q->left);

                if( q->right ) Q.push(q->right);
            }
        }

        return maxDepth;
    }
};

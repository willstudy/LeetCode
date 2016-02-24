/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest
path from the root node down to the nearest leaf node.
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
 * 注意：左右孩子均为0的节点，才是孩子节点。在层次遍历中，注意在弹出一层的节点时，
 * 不要使用Q.size()作为临界值，因为它在不停的变化！！吃了好几次亏了。
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        queue<TreeNode *> Q;
        int result = 0;
        if( root == NULL ) return result;

        Q.push( root );

        while( !Q.empty() )
        {
            result++;
            int size = Q.size();
        /* 循环内不要使用Q.size()作为临界值，因为Q的size会一直变化！！而且效率低下 */
            for( int j = 0; j < size; j++ )
            {
                TreeNode * node = Q.front();

                if( node->left ) Q.push( node->left );
                if( node->right ) Q.push( node->right );

                Q.pop();

                if( node->left == NULL && node->right == NULL ) return result;
            }
        }
        return result;
    }
};

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given
nodes in the BST.According to the definition of LCA on Wikipedia: “The lowest common
ancestor is defined between two nodes v and w as the lowest node in T that has both v and w
as descendants (where we allow a node to be a descendant of itself).”

          _______6______
         /              \
     ___2__           ___8__
    /      \         /      \
   0        4       7       9
 /  \
3   5

For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of
itself according to the LCA definition.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //找到一个节点，要大于等于小节点，小于等于大节点的值
        TreeNode * node = root;
        int left;
        int right;

        if( p->val > q->val )
        {
            left = q->val;
            right = p->val;
        }
        else
        {
            left = p->val;
            right = q->val;
        }

        while( node != NULL )
        {
            if( node->val >= left && node->val <= right ) return node;  // 符合要求
            if( node->val > right ) node = node->left;  // 往左子树查询
            if( node->val < left ) node = node->right;  // 往右子树查询
        }
    }
};

/*
Given two binary trees, write a function to check if they are equal
or not.Two binary trees are considered equal if they are structurally
identical and the nodes have the same value.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        queue<TreeNode * > P;
        queue<TreeNode * > Q;

        if( p == NULL && q == NULL ) return true;

        if( p != NULL && q != NULL && p->val == q->val )
        {
            P.push(p);
            Q.push(q);
        }
        else return false;

        while( ( ! P.empty() ) && ( ! Q.empty() ) )
        {
            TreeNode * node1 = P.front();
            TreeNode * node2 = Q.front();

            P.pop();
            Q.pop();

            if( node1 == NULL && node2 == NULL )
            {
                continue;
            }

            if( node1 != NULL && node2 != NULL && node1->val == node2->val )
            {

                if( node1->left && node2->left )
                {
                    if( node1->left->val == node2->left->val )
                    {
                        P.push(node1->left);
                        Q.push(node2->left);
                    }
                    else return false;
                }
                if( node1->right && node2->right )
                {
                    if( node1->right->val == node2->right->val )
                    {
                        P.push(node1->right);
                        Q.push(node2->right);
                    }
                    else return false;
                }
                if( ( node1->left == NULL && node2->left != NULL ) ||
                    ( node1->left != NULL && node2->left == NULL ) )
                    return false;
                if( ( node1->right == NULL && node2->right != NULL ) ||
                    ( node1->right != NULL && node2->right == NULL ) )
                    return false;
            }
            else return false;
        }

        if( P.empty() && Q.empty() ) return true;
        else return false;
    }
};

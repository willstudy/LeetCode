/*
Given a binary tree, return the level order traversal of its nodes' values.
(ie, from left to right, level by level).
*/
/*
 * 二叉树的层次遍历，使用队列，可以很好的实现。
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> Q;

        if( root == NULL ) return result;

        Q.push( root );

        while( !Q.empty() )
        {
            vector<int> temp;

            int num = Q.size();    // 这里要把二叉树上一层的节点数保存下来
            for( int i = 0; i < num; i++ )
            {
                TreeNode * p = Q.front();

                if( p->left ) Q.push( p->left );
                if( p->right ) Q.push( p->right );

                temp.push_back( p->val );

                Q.pop();
            }

            result.push_back( temp );
        }
        return result;
    }
};

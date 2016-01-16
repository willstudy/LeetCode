/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values.
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
        3
       / \
      9  20
        /  \
       15   7
return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;

        if( root == NULL ) return result;

        queue<TreeNode *> Q;
        stack<vector<int>> S;

        Q.push( root );

        while( !Q.empty() )
        {
            int size = Q.size();
            int i = 0;
            vector<int> temp;

            TreeNode * node;
            for( i = 0; i < size; i++ )
            {
                node = Q.front();

                if( node->left ) Q.push( node->left );
                if( node->right ) Q.push( node->right );

                Q.pop();

                temp.push_back( node->val );
            }
            S.push(temp);
        }

        while( !S.empty() )
        {
            result.push_back( S.top() );
            S.pop();
        }

        return result;
    }
};

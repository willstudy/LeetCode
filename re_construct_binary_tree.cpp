/*
给定一个二叉树的前序遍历和中序遍历，重构成这颗二叉树。

来源：剑指Offer
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
      struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {

        int length = in.size();

        if( length == 0 )
          return NULL;

        vector<int> pre_left;
        vector<int> pre_right;
        vector<int> in_left;
        vector<int> in_right;

        /* 创建根节点，根节点肯定是前序遍历的第一个数 */
        TreeNode * head = new TreeNode(pre[0]);

        /* 找到中序遍历根节点所在位置,存放于变量root_index中 */

        int root_index = 0;
        for(int i = 0; i < root_index; i++)
        {
          if ( in[i] == pre[0] )
          {
            root_index = i;
            break;
          }

        }

        /* 对于中序遍历，根节点左边的节点位于二叉树的左边，
         * 根节点右边的节点位于二叉树的右边
         * 利用上述这点，对二叉树节点进行归并
         */
         for( int i = 0; i < root_index; i++ )
         {
           in_left.push_back(in[i]);
           pre_left.push_back(pre[i+1]);
         }

        for( int i = root_index + 1; i < length; i++ )
        {
          in_right.push_back(in[i]);
          pre_right.push_back(pre[i]);
        }

        head->left=reConstructBinaryTree(left_pre,left_in);
        head->right=reConstructBinaryTree(right_pre,right_in);

        return head;
    }
};

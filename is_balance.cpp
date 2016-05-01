/*
判断一棵树是否是平衡二叉树

思路：后序遍历的时候，保存每个节点对应的二叉树的深度。
*/
class Solution {
public:
    bool is_balance(TreeNode * root, int * depth)
    {
        if( root == NULL ) {
            *depth = 0;
            return true;
        }
        int left = 0;
        int right = 0;
        if( is_balance(root->left, &left) && is_balance(root->right, &right)) {
            int offset = left - right;

            if( offset > 1 || offset < -1 ) return false;

            *depth = 1 + ( left > right ? left : right );

            return true;
        }

        return false;
    }

    bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth = 0;
        return is_balance(pRoot, &depth);
    }
};

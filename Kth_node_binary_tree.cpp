/*
二叉搜索数的第K个节点

思路：
二叉搜索树的中序遍历，第K个值
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, unsigned int k)
    {
        if( pRoot == NULL || k <= 0 ) return NULL;

        int count = 1;

        stack<TreeNode *> S;
        S.push(pRoot);

        TreeNode * node = S.top();
        S.pop();
        while( node || !S.empty() ) {

            while( node ) {
                S.push(node);
                node = node->left;
            }

            node = S.top();

            if( count == k ) return node;

            S.pop();
            count++;

            node = node->right;
        }

        return NULL;
    }


};

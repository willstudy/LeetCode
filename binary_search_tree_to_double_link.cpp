/*
把二叉搜索树转换成双向链表的形式，其中左孩子指向前驱节点，右孩子指向后继节点
*/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void convert_node( TreeNode * root, TreeNode ** last_node )
    {
        if( root == NULL ) return;

        TreeNode * current = root;

        if( current->left ) convert_node( current->left, last_node );
        // 找前驱
        current->left = *last_node;
        if( *last_node != NULL ) {
            (*last_node)->right = current;
        }

        *last_node = current;
        if( current->right != NULL ) convert_node( current->right, last_node );

    }

    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode * last_node = NULL;

        convert_node( pRootOfTree, &last_node );

        //返回头结点
        TreeNode * head = last_node;
        while( head != NULL && head->left != NULL ) {
            // 前驱节点
            head = head->left;
        }
        return head;
    }
};

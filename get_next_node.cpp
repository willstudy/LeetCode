/*
给定二叉树的一个节点，返回它中序遍历的下一个节点

思路：
如果该节点有右孩子，则下一个节点就是右孩子的最左节点
如果该节点没有右孩子，则判断该节点是否是父节点的左孩子，如果是就返回父节点
否则继续判断父节点是否是父节点的父节点的左孩子
*/
using namespace std;
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if( pNode == NULL ) return NULL;

        if( pNode->right ) {
            TreeLinkNode * node = pNode->right;
            while( node->left ) {
                node = node->left;
            }
            return node;
    	} else {
        	TreeLinkNode * parent = pNode->next;
            while( parent ) {
                if( pNode == parent->left ) return parent;
                pNode = parent;
                parent = pNode->next;
            }
            return parent;
    	}
    }
};

/*
判断二叉树是否是镜像二叉树

思路：
层次遍历，注意入队列的顺序，第一个节点的左孩子，与第二个节点的右孩子比较，分别入队
第一个节点的右孩子，与第二个节点的左孩子比较，分别入队
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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if( pRoot == NULL ) return true;

    	queue<TreeNode * > Q;

        if( pRoot->left ) Q.push(pRoot->left);
        if( pRoot->right ) Q.push(pRoot->right);

        while( !Q.empty() ) {
            int size = Q.size();
            for( int i = 0; i < size; i += 2 ) {
                /* 某一层为奇数个顶点 */
                if( size & 1 ) return false;
                TreeNode * node1 = Q.front();
                Q.pop();
                TreeNode * node2 = Q.front();
                Q.pop();

                if( node1->val != node2->val ) return false;

                if( node1->left ) {
                    if( node2->right == NULL ) return false;
                    if( node1->left->val != node2->right->val ) return false;

                    Q.push(node1->left);
                    Q.push(node2->right);
                }
                else if( node2->right ) return false;

                if( node1->right ) {
                    if( node2->left == NULL ) return false;
                    if( node1->right->val != node2->left->val ) return false;

                    Q.push(node1->right);
                    Q.push(node2->left);
                }
                else if( node2->left ) return false;
            }
        }
        return true;
    }

};

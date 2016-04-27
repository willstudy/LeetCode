/*
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
如果是返回True,否则返回False。假设输入的数组的任意两个数字都互不相同。
*/
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {

        int size = sequence.size();
        if( size == 0 ) return false;

        while( size-- ) {
        	int i = 0;
            while( sequence[i++] < sequence[size] );
            while( sequence[i++] > sequence[size] );

            if( i < size ) return false;
        }
        return true;
    }
};

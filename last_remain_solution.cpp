/*
约瑟夫环的问题：

n个人连成一圈，数到第m个就去掉它，问最后剩下的是谁？f(n,m)表示
此问题的解

把删除之后的后半部分放到数组前方，把f(n,m)变成了f`(n-1, m)
有一种映射关系：

f(n,m) = f`(n-1, m) = [f(n-1, m) + m] % n;

从底往上计算，当n=0时，很显然最后剩下的值就是0
*/
class Solution {
public:
    int LastRemaining_Solution(unsigned int n, unsigned int m)
    {
        if( n < 1 || m < 1 ) return -1;

        int last = 0;
        for( int i = 2; i <= n; i++ ) {
            last = (last + m) % i ;
        }
        return last;
    }
};

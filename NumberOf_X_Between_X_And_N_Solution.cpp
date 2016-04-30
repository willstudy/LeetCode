/*
给定一个整数 N 和 X，其中 1 <= X <= 9 。先判断从 1 到 N 之间的数列中，共出现了多少次 X

思路：

总结一下以上的算法，可以看到，当计算右数第 i 位包含的 X 的个数时：

取第 i 位左边（高位）的数字，乘以 10i−1，得到基础值 a。
取第 i 位数字，计算修正值：
如果大于 X，则结果为 a+10i−1。
如果小于 X，则结果为 a。
如果等 X，则取第 i 位右边（低位）数字，设为 b，最后结果为 a+b+1。
相应的代码非常简单，效率也非常高，时间复杂度只有 O(log10n)。
*/

class Solution {
public:

    long power(int base, int exp)
    {
        int result = 1;
        while( exp ) {
            result *= 10;
            exp--;
        }
        return result;
    }

    int NumberOf_X_Between_X_And_N_Solution(int n, int x)
    {
    	if( n <= 0 ) return 0;

        int sum = 0;
        int latter = 0;
        int exp = 0;

        while( n ) {
            int mod = n % 10;
            n = n / 10;

            if( n ) sum += n * power(10, exp);
            if( mod > x ) sum += power(10, exp);
            else if( mod == x ) sum += latter + 1;

            latter += mod * power(10, exp);
            exp++;
        }

        return sum;
    }
};

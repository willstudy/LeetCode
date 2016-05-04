/*
使用位操作实现加法

思路：
先使用 异或 做不带进位的加法，
然后使用 与 操作得到需要进位的数值大小
再用 异或做 不带进位的加法，直到不需要进位为止
*/
class Solution {
public:
    int Add(int num1, int num2)
    {
		do {
            /* 不带进位的加法 */
            int sum = num1 ^ num2;
            /* 加上待进位的数值 */
            int carray = (num1 & num2) << 1;
            num1 = sum;
            num2 = carray;
        } while( num2 );

        return num1;
    }
};

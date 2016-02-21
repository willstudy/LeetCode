/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.
*/

/*
 * 计算 n 阶乘的结果末尾0的个数，只有5相乘时，才有可能末尾为0
 * 假如 n = 100，需要计算 100 中含有的5的个数为20 ，再计算20中含有5的个数4，总共24个
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n)
        {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};

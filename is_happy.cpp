/*
A happy number is a number defined by the following process: Starting with
any positive integer, replace the number by the sum of the squares of its digits,
and repeat the process until the number equals 1 (where it will stay), or it loops
endlessly in a cycle which does not include 1. Those numbers for which this process
ends in 1 are happy numbers.

Example: 19 is a happy number

12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/
class Solution {
public:
    inline int digitSquareSum(int n) {

        int sum = 0, tmp;

        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

 /*
  * 进行两次求digitSquareSum，若经过2次求之后，值相同，说明这个值不会被这个过程改变了,
  * 可以退出循环了
  */
    bool isHappy(int n) {

        int slow, fast;
        slow = fast = n;

        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
            if(fast == 1) return 1;

        } while( slow != fast );
        return 0;
    }
};

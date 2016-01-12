/*
Given an integer, write a function to determine if it is a power of two.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if( n <= 0 ) return false;

        int num = 0;

        while( n )
        {
            n = n & ( n - 1 );
            ++num;    // 计算 n 中 1的个数,若为2的幂，只能含有1位1

            if( num > 1 ) return false;
        }
        return true;
    }

    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }

    bool isPowerOfTwo(int n) {
        return (n > 0) && (!(2147483648%n)); //2147483648 是2^31，跟powerOfThree题目类似
    }
};

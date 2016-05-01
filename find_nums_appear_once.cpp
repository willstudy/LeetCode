/*
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。

思路：

先把所有数字异或，其结果中必有1位含有1，因为有2个数字不同啊

以这一位1为分界线，把数组分2半，这2半分别含有只出现一次的数字

然后对这2个数组进行异或，2个结果就是这两个只出现一次的数字
*/
class Solution {
public:
    /* 从最低位开始，找出第一个位是1的位置 */
    int find_index( int result )
    {
        int index = 0;
        while( result ) {
            if( result & 1 ) return index;
            index++;
            result >>= 1;
        }
        return index;
    }
    /* 判断第index位是否是1 */
    bool is_bit_1( int data, int index ) {

        int num = 1 << index;

        return data & num;
    }

    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int result = 0;
        int size = data.size();

        if( size <= 1 ) return;

        for( int i = 0; i < size; i++ )
            result ^= data[i];

        int index_of_1 = find_index( result );

        for( int i = 0; i < size; i++ ) {
            if( is_bit_1(data[i], index_of_1) ) {
                *num1 ^= data[i];
            }
            else {
                *num2 ^= data[i];
            }
        }
    }
};

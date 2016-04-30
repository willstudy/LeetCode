/*
计算丑数：因子中只包含2，3，5的数说明是丑数

第一个丑数为1， 计算第n个丑数的值

思路：

因为第n个丑数的值是由前面丑数乘2或3或5得来的，那么可以保存前面的丑数值
直接计算下一个丑数的值，分别用ugly_num2, ugly_num3, ugly_num5指针
指向被5乘得到的丑数的值，每当新生成一个丑数时，取三者的最小值，如下

new_ugly = min(2*ugly_num2, min(3*ugly_num3, 5*ugly_num5))
*/
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
    	if( index <= 0 ) return 0;

        int * ugly_num = new int[index];
        ugly_num[0] = 1;

        int next_ugly = 1;
        int * ugly_num2 = ugly_num;
        int * ugly_num3 = ugly_num;
        int * ugly_num5 = ugly_num;

        while( next_ugly < index ) {
            int miner = min( *ugly_num2*2, min(*ugly_num3*3, *ugly_num5*5) );
            ugly_num[next_ugly] = miner;

            while( *ugly_num2 * 2 <= ugly_num[next_ugly] ) ++ugly_num2;
            while( *ugly_num3 * 3 <= ugly_num[next_ugly] ) ++ugly_num3;
            while( *ugly_num5 * 5 <= ugly_num[next_ugly] ) ++ugly_num5;

            next_ugly++;
        }

        return ugly_num[index-1];
    }
};

/*
判断一个数组中一串数字是否是“顺子”，0可以被当成任意的数

思路：
先排序，计算0的个数 number_of_zero
再计算相邻数之间的间隔多大 number_of_gap
比较两者的值
*/
class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        int size = numbers.size();
        if( size <= 0 ) return 0;

        sort( numbers.begin(), numbers.end() );

        int number_of_zero = 0;
        for( int i = 0; i < size; i++ ) {
            if( numbers[i] == 0 ) number_of_zero++;
        }

        int number_of_gap = 0;
        for( int i = number_of_zero+1; i < size; i++ ) {
            if( numbers[i] == numbers[i-1] ) return false;
            number_of_gap += numbers[i] - numbers[i-1] - 1;
        }

        return number_of_gap > number_of_zero ? false : true;
    }
};

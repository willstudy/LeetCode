/*
找出连续的正整数序列，使其之和为sum，保存这样的子序列

思路：

设置small和big指针，记录当前的序列的和，
若大于sum，要增加small，并且减去small的值
若小于sum，要增加big，并且加上big的值
*/

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;

        if( sum < 3 ) return result;

        int small = 1;
        int big = 2;
        int mid = (sum+1) >> 1;
        int cur_sum = small + big;

        while( small < mid && big < sum ) {

            while( cur_sum > sum ) {
                cur_sum -= small;
                small++;
            }

            if( cur_sum == sum ) {
                vector<int> temp;

                for( int i = small; i <= big; i++ ) {
                    temp.push_back(i);
                }
                result.push_back(temp);
            }

            big++;
            cur_sum += big;
        }
       	return result;
    }
};

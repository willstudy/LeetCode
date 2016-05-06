/*
找出滑动窗口中的最大值，如：如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
{[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
{2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。

思路：
求解滑动窗口内部的最大值，记住最大值的下标priot, 然后移动滑动窗口，
根据priot是否在当前窗口范围内而更新最大值和下标
*/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> result;

        int num_size = num.size();

        if( num_size <= 0 || size == 0 || size > num_size ) return result;

        /* 初始化 */
        int MIN_INT = -100000000;
        int max_num = MIN_INT;
        int priot = 0;
        for( int i = 0; i < size; i++ ) {
            if( num[i] > max_num ) {
                max_num = num[i];
                priot = i;
            }
        }

        result.push_back(max_num);

        for( int i = size; i < num_size; i++ ) {
            if( i - size + 1 > priot ) {
                max_num = MIN_INT;
                for( int j = i-size+1; j <= i; j++ ) {
                    if( num[j] > max_num ) {
                        priot = j;
                        max_num = num[j];
                    }
                }
                result.push_back(max_num);
            }
            else if( num[i] > max_num ) {
                max_num = num[i];
                priot = i;
                result.push_back(max_num);
            } else {
                result.push_back(max_num);
            }
        }

        return result;
    }
};

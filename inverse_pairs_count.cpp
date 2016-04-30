/*
求数组中的逆序数的个数，如数组[5,7,6,4]
(7,5)(7,6)(7,4)(6,5)(6,4)(5,4)都是逆序数

思路：
利用归并排序的思想，在归并的过程中直接统计逆序数的个数
5 7
4 6
归并7和6的时候，7对应的逆序数是 5 和 4 和 6
*/
class Solution {
public:

    int inverse_pairs_count( vector<int> & data, vector<int> & copy, int start, int end )
    {
    	if( start >= end ) {
            copy[start] = data[start];
            return 0;
        }

        int mid = (end + start) >> 1;
        int left = inverse_pairs_count( data, copy, start, mid);
        int right = inverse_pairs_count( data, copy, mid+1, end);
        /* 左右2个数组的最右边下标 */
        int left_end = mid;
        int right_end = end;
        int index_copy = end;
        int count = 0;

        while( left_end >= start && right_end >= mid+1 ) {
            if( data[left_end] > data[right_end] ) {
                copy[index_copy--] = data[left_end--];
                count += right_end - mid;
            } else {
                copy[index_copy--] = data[right_end--];
            }
        }

        while( left_end >= start ) copy[index_copy--] = data[left_end--];
        while( right_end >= mid+1 ) copy[index_copy--] = data[right_end--];

        for( int i = start; i <= end; i++ ) {
            data[i] = copy[i];
        }

        return left + right + count;
    }

    int InversePairs(vector<int> data) {
        int size = data.size();
        if( size <= 0 ) return 0;

        vector<int> copy(data.begin(), data.end());

        return inverse_pairs_count( data, copy, 0, size - 1);
    }
};

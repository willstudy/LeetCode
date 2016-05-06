/*
找出一串数字流中的中位数

思路：
查找第K个数的思路是一样的，若数组长度 N 为奇数，直接查找第 (N-1)/2的数字
如 N 为偶数 则查找 (N-1)/2 和 (N-1)/2 + 1 的数字
*/
class Solution {
public:
    vector<int> array;

    int partition( vector<int> & array, int left, int right )
    {
        int priot = array[right];
        int i = left - 1;

        for( int j = left; j < right; j++ ) {
            if( array[j] <= priot ) {
                i++;
                swap( array[i], array[j] );
            }
        }

        swap( array[i+1], array[right] );
        return i + 1;
    }

    int find_K_num( vector<int> & array, int left, int right, int k )
    {
        int size = array.size();

        int mid = partition( array, left, right );

        if( mid == k ) return array[k];
        else if( mid > k ) {
            return find_K_num( array, left, mid - 1, k );
        }
        else {
            return find_K_num( array, mid + 1, right, k );
        }

        return array[mid];
    }

    void Insert(int num)
    {
        array.push_back(num);
    }

    double GetMedian()
    {
    	int size = array.size();
        int left = 0;
        int right = size - 1;

        if( size & 1 ) {
            return find_K_num( array, left, right, (size - 1) / 2 );
        }
        else {
            return (find_K_num( array, left, right, (size - 1) / 2) +
                find_K_num( array, left, right, (size - 1) / 2 + 1) ) / 2.0;
        }
    }

};

/*
找出一个已排序的数组中，数字K出现的次数

思路：
通过二分查找的思想，找到K第一次出现的位置和最后一次出现的位置
即可得到K出现的次数了
*/
class Solution {
public:
     int get_first_K( const vector<int> & input, int start, int end, int k )
    {

        if( start > end ) return -1;

        int mid = ( start + end ) >> 1;

         if( input[mid] == k ) {
           	if( ( mid-1 >= 0 && input[mid-1] != k) || mid == 0 ) {
            	return mid;
            }
            else {
              	end = mid - 1;
           	}
        } else if( input[mid] > k ) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        return get_first_K( input, start, end, k );
    }

    int get_last_K( const vector<int> & input, int size, int start, int end, int k )
    {
        if( start > end ) return -1;

        int mid = ( start + end ) >> 1;

        if( input[mid] == k ) {
           	if( (mid+1 <= size - 1 && input[mid+1] != k) || mid == size - 1 ) {
            	return mid;
            } else {
                start = mid + 1;
            }
        } else if( input[mid] > k ) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
        return get_last_K( input, size, start, end, k );
    }

    int GetNumberOfK(vector<int> data ,int k) {
        int size = data.size();

        if( size <= 0 ) return 0;

        int left = get_first_K( data, 0, size - 1, k );
        int right = get_last_K( data, size, 0, size - 1, k );

        if( left == -1 || right == -1 ) return 0;

        return right - left + 1;
    }
};

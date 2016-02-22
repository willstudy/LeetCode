/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

/*
 * 杨辉三角问题，注意这题是从第0层开始计数的，即
 * 0th : [1]
 * 1th : [1,1]
 * 2th : [1,2,2,1]
 * ...
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;

        if( rowIndex < 0 ) return result;

        result.push_back(1);

        for( int i = 1; i <= rowIndex; i++ )
        {
            vector<int> temp;

            temp.push_back(1);

            for( int j = 1; j < i; j++ ) // result里面保存上一层的数字
            {
                temp.push_back( result[j] + result[j-1] );
            }

            temp.push_back(1);
            result.swap( temp );
        }
        return result;
    }
};

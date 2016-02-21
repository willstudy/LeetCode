/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/
/*
 * 打印杨辉三角
 */
class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> result;

        for( int i = 0; i < numRows; i++ )
        {
            vector<int> temp;

            temp.push_back(1);

            for( int j = 1; j < i; j++ )
            {
              /* 每一层的元素由1作为开头和结束，且下一个元素是上一层元素对应当前坐标和前一坐标元素 */
                temp.push_back( result[i-1][j] + result[i-1][j-1] );
            }

            if( i > 0 ) temp.push_back(1);

            result.push_back(temp);
        }

        return result;
    }
};

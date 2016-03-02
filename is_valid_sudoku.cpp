/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

A partially filled sudoku which is valid.

*/
/*
 * 每一列、每一列不能包含同样的数字，每9个元素组成的块中，也不能包含同样的数字
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        int row[9][9] = {0};
        int col[9][9] = {0};
        int block[9][9] = {0};

        for( int i = 0; i < board.size(); i++ )
        {
            vector<char> temp = board[i];
            for( int j = 0; j < temp.size(); j++ )
            {
                if( board[i][j] != '.' )
                {
                    int index = board[i][j] - '1';

                    /* 分别记录第几个行、列、块，内部包含此数的个数，
                     * 把这个数当做数组的下标
                     */
                    row[i][index]++;
                    col[j][index]++;
                    /* 当i < 3 || j < 3时，属于第0个块 */
                    block[(i/3)*3 + j/3][index]++;

                    if( row[i][index] > 1 || col[j][index] > 1
                       || block[(i/3)*3 + j/3][index] > 1 )
                       return false;

                }
            }
        }

        return true;
    }
};

/*
一个长度为n的数组中含有0到n-1的数字，判断这个数组中是否含有重复的数字。

思路：
因为数组中的数字范围是0到n-1，可以使第i个数当做数组的下标，加上数组的长度，
当重复的数字出现时，发现它所指的位置已经大于数组长度了
*/
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {

        if( length <= 0 ) return false;

        for( int i = 0; i < length; i++ ) {
            int index = numbers[i];
            /* 减去第一个数出现时，所加上的  */
            if( index >= length ) {
                index -= length;
            }
            /* 如果此时仍大于length，说明出现了两次 */
            if( numbers[index] >= length ) {
                *duplication = numbers[index] - length;
                return true;
            }
            numbers[index] = numbers[index] + length;
        }

        return false;
    }
};

/*
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
/*
 * 数组中的每位结合起来代表一个数，对其加1操作，若最低位不是9，直接加1返回，若是9的话，需要进行前一位的判断
 * 如果所有元素都是9，那么就需要增加一位，且末位为0，高位为1
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int n = digits.size();

        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }

        digits[0] = 1;
        digits.push_back( 0 );
        return digits;
    }
};

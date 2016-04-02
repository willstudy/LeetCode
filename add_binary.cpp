/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
 * 二进制字符串相加：从后往前加，最后把结果翻转
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int aSize = a.size();
        int bSize = b.size();
        int i = aSize - 1;
        int j = bSize - 1;
        int ascend = 0;

        while( i >= 0 && j >= 0 ) {
            if( a[i] == '1' && b[j] == '1' && ascend ) {
                result += '1';
                ascend = 1;
            }else if( a[i] == '1' && b[j] == '1' ) {
                result += '0';
                ascend = 1;
            }else if( a[i] == '1' && ascend ) {
                result += '0';
                ascend = 1;
            }else if( b[j] == '1' && ascend ) {
                result += '0';
                ascend = 1;
            }else if( ascend ){
                result += '1';
                ascend = 0;
            }else if( a[i] == '1' ) {
                result += '1';
                ascend = 0;
            }else if( b[j] == '1' ) {
                result += '1';
                ascend = 0;
            }
            else {
                result += '0';
                ascend = 0;
            }
            i--;
            j--;
        }

        while( i >= 0 ) {
            if( ascend && a[i] == '1' ) {
                result += '0';
                ascend = 1;
            }else if( a[i] == '1' || ascend ) {
                result += '1';
                ascend = 0;
            }else {
                result += '0';
                ascend = 0;
            }
            i--;
        }

        while( j >= 0 ) {
            if( ascend && b[j] == '1' ) {
                result += '0';
                ascend = 1;
            }else if( b[j] == '1' || ascend ) {
                result += '1';
                ascend = 0;
            }else {
                result += '0';
                ascend = 0;
            }
            j--;
        }

        if( ascend ) {
            result += '1';
        }

        j = result.size();

        for( i = 0; i < j / 2; i++ ) {
            char temp = result[i];
            result[i] = result[j-1-i];
            result[j-1-i] = temp;
        }
        return result;
    }
};

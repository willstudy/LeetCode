/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string
*/

class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        int count = 1;

        while( count < n ) {
            str = convertToCountAndSay(str);
            count++;
        }
        return str;
    }

    string convertToCountAndSay(string str) {
        int p = 0;
        string res;
        while(p < str.length()) {
            char cur_num = str[p];
            int count = 0;
            while(p < str.length() && str[p] == cur_num) { count++; p++; }
            res += count + '0';
            res += cur_num;
        }
        return res;
    }
};

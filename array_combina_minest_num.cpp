/*
一个整形数组 [] = { 2, 432, 432, 123, ... } 如何排列组合成最小的一个数？

思路：把整形数组转换成字符串数组，并对字符串数组进行排序
时间复杂度：O(nlgn)
*/
class Solution {
public:

    string int2string(int n)
    {
        stringstream s;
        string result;

        s << n;

        s >> result;

        return result;
    }

    static bool comp( string a, string b )
    {
    	string str1 = a + b;
        string str2 = b + a;

        return str1 < str2;
    }

    string PrintMinNumber(vector<int> numbers) {
        int size = numbers.size();
        string result;

        if( size == 0 ) return result;

        vector<string> temp;
        for( int i = 0; i < size; i++ ) {
            temp.push_back(int2string(numbers[i]));
        }

        sort( temp.begin(), temp.end(), comp );

        for( int i = 0; i < size; i++ ) {
            result = result + temp[i];
        }

        return result;
    }
};

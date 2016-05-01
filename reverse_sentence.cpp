/*
翻转英文单词，比如 I am student. 翻转成 student. a am I

思路：先把词语整体翻转，然后翻转每个单词
*/
class Solution {
public:
    void reverse(string & str, int start, int end)
    {
        while( start < end ) {
            char c = str[start];
            str[start] = str[end];
            str[end] = c;
            start++;
            end--;
        }
    }

    string ReverseSentence(string str) {
        string result;
        int size = str.size();

        if( size <= 0 ) return result;

        result = str;

        reverse(result, 0, size-1 );

        int i = 0;
        while( i < size ) {

            int start = i;
            /* 跳过单词前的空格 */
            while( result[start] == ' ' && start < size ) start++;

            int end = start;
            /* 计算单词末尾的长度 */
            while( result[end] != ' ' && end < size ) end++;

            reverse(result, start, end-1 );
            i = end;
        }
        return result;
    }
};

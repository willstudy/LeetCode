/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
*/
int lengthOfLastWord(char* s) {
    char * p = s;
    int length = 0;

    if( p == NULL ) return 0;

    while( *p != '\0' )
    {
        p++;
    }

    p--;      // 从字符串结尾符'\0'回退到最后一个字符
    while( *p == ' ' ) p--;   // 跳过最后的空格字符
    while( *p != ' ' && p >= s )
    {
        p--;
        length++;
    }

    return length;

}

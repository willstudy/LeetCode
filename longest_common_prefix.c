/*
Write a function to find the longest common prefix string amongst an array of strings.
*/
char* longestCommonPrefix(char** strs, int strsSize) {
    if( strs[0] == NULL ) return "";

    int size = strlen( strs[0] );
    int i = 0;
    int j = 0;
    char * result = (char *)malloc(size);

    memset( result, 0, size );

    for( i = 0; i < size; i++ )
    {
        for( j = 1; j < strsSize; j++ )
        {
            if( i >= strlen(strs[j]) ) return result;

            if( strs[j][i] != strs[j-1][i] ) return result;
        }
        result[i] = strs[0][i];
    }
    result[i] = '\0';

    return result;
}

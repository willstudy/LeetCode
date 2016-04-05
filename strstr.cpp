/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size1 = haystack.size();
        int size2 = needle.size();
        int i, j;
        int index = 0;

        i = 0;
        j = 0;
        while( i < size1 && j < size2 )
        {
            i = index;

            while( haystack[i] == needle[j] && j < size2 && i < size1 )
            {
                i++;
                j++;
            }

            if( j == size2 ) break;

            j = 0;
            index++;
        }

        if( j == size2 ) return i - j;

        return -1;
    }
};
/*
 * KMP algorithm
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> generate( string pattern )
{
	int size = pattern.size();
	int len = 0;
	int i;

	vector<int> next(size, 0);

	for( i = 1, len = 0; i < size; )
	{
		if( pattern[i] == pattern[len] )
		{
			next[i++] = ++len;
		}
		else if( len ) len = next[len-1];
		else next[i++] = 0;
	}
	return next;
}


int strstr( string text, string pattern )
{
	int size1 = text.size();
	int size2 = pattern.size();
	int i, j;

	vector<int> next = generate(pattern);

	for( i = 0, j = 0; i < size1; )
	{
		if( text[i] == pattern[j] )
		{
			i++;
			j++;
		}

		if( j == size2 ) return i - j;

		if( i < size1 && text[i] != pattern[j] )
		{
			if( j ) j = next[j-1];
			else i++;
		}
	}
	return -1;
}

int main()
{
	string text = "abcdefgabcdabcd";
	string pattern = "abcdabcd";

	cout << strstr( text, pattern ) << endl;

	return 0;

}

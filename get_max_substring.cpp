/*
美团的一道算法题，在一个字符串中删除任意位置，任意多的字符，使之剩下组成的字符最大

今天遇到了一个特别NICE的面试官，很有耐心给我指点错误~~

刚开始我这个问题连O(n^2)的方法都想错了。。
时间复杂度计算错误，空间复杂度也能计算错误！！！
真是醉了，要是换一个面试官的话，
心里一定在想这个大水比。。。早就应该狗带了。。。

现在把这个算法C语言实现了一下，在机器上测试了一下，目前测试的例子都是正确的结果
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 128

/*
 *  时间复杂度：O(n)，空间复杂度：O(1)
 */

char * get_max_substring( char * array )
{
	if( array == NULL ) return NULL;

	char * result = (char *)malloc(sizeof(MAX_STR));

	if( result == NULL ) return NULL;

	char * ptr = array;
	char max_char = 0;
	int priot = 0;

	result[priot] = *ptr;
	ptr++;

	while( *ptr != '\0' ) {

		if( *ptr > *(ptr-1)  ) {
			result[priot] = *ptr;
			ptr++;
		}
		else {

			max_char = *(ptr - 1);

			while( *ptr != '\0' ) {
				if( *(ptr+1) != '\0' ) {
					if( *(ptr+1) > *ptr ) {
          /* 找到了更大的字符了，更新下标 */
						if( *(ptr+1) > max_char ) {
							max_char = *(ptr+1);
							priot = -1;
						}
						result[priot+1] = *(ptr+1);
						ptr++;
					}
					else {
						priot += 1;
						result[priot] = *ptr;
						ptr++;
					}
				}
				/* the last one */
				else {
					priot += 1;
					result[priot] = *ptr;
					result[priot+1] = '\0';

					return result;
				}
			}
		}
	}

	result[priot+1] = '\0';

	return result;
}

int main()
{
	char array[] = "abcdabcd";
	char * result = NULL;

	result = get_max_substring(array);

	if( result )
		printf( "%s\n", result );

	return 0;
}

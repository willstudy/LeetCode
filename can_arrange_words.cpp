/*
一个字符串数组判断其中的单词，是否可以首尾连接，
即一个单词的结尾字母，要与下一个单词的开头字母相同。如：

“word desk key yes”  return 1

其他返回 -1
*/
#include <iostream>
#include <cstdio>

using namespace std;

int canArrangeWords(int num,char** arr){

int visit[num];
int i,j;

for( i = 0; i < num; i++ ) {

  int flag = 0;
  for( j = 0; j < num; j++ ) visit[j] = 0;

  char * wordA = arr[i];
  char * endA = wordA;

  while( *endA != '\0' ) endA++;
  endA--;

  visit[i] = 1;

  while( flag < num ) {
    for( j = 0; j < num; j++ ) {
      if( visit[j] == 1 ) continue;

      char * wordB = arr[j];
      char * endB = wordB;

      if( *endA == *wordB ) {

      while( *endB != '\0' ) endB++;
      endB--;

      endA = endB;
      flag++;
      visit[j] = 1;
      break;
      }
    }
    if( j == num ) break;
  }
/* 如果所有单词都可以首尾连接的话 */
  if( flag == num - 1 ) return 1;
}

return -1;
}

int main()
{
  char * arr[] = {"oop","hello","pc"};

  cout << canArrangeWords(3, arr) << endl;

  return 0;
}

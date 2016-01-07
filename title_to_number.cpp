/*
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/

class Solution {
public:
    int titleToNumber(string s) {

      if( s.empty() ) return 0;

      int size = s.size();
      int result = s[0] - 0x40;

      for( int i = 1; i < size; i++ )
      {
          result = result * 26 + (s[i] - 0x40);
      }

      return result;
    }
};

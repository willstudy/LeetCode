/*
Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:
You may assume the string contains only lowercase alphabets.

Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
*/

class Solution {
public:
    bool isAnagram(string s, string t) {

        int len1 = s.size();    // 主要是判断俩个字符串中，每个所包含字母的个数是否相等
        int len2 = t.size();
        int string_map[26] = {0} ;

        if( len1 != len2 ) return false;

        for( int i = 0; i < len1; i++ )
        {
            string_map[ s[i] - 'a' ] += 1;
            string_map[ t[i] - 'a' ] -= 1;
        }

        for( int i = 0; i < len1; i++ )
        {
            if( string_map[t[i] - 'a'] != 0 ) return false;
        }

        return true;
    }
};

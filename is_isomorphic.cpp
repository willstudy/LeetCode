/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while
preserving the order of characters. No two characters may map to the same character
but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int tab1[128], tab2[128];

        memset( tab1, 0xff, 128*sizeof(int) );
        memset( tab2, 0xff, 128*sizeof(int) );

        for (int i = 0; i < s.size(); ++i)
        {
            int a = s[i], b = t[i];

            if (tab1[a] == -1 && tab2[b] == -1)
            {
                tab1[a] = b; tab2[b] = a;
            }
            else if (tab1[a] != -1 && tab2[b] != -1)
            {
                if ( tab1[a] != b || tab2[b] != a ) return false;
            }
            else return false;
        }

        return true;
    }
};

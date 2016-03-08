/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}"
are all valid but "(]" and "([)]" are not.
*/
class Solution {
public:
    bool isValid(string s) {
        stack<char> S;

        for( int i = 0; i < s.size(); i++ )
        {
            if( s[i] == '(' || s[i] == '[' || s[i] == '{' )
            {
                S.push(s[i]);
            }
            else
            {
                if( S.empty() ) return false;

                else if( s[i] == ')' && S.top() != '(' ) return false;

                else if( s[i] == ']' && S.top() != '[' ) return false;

                else if( s[i] == '}' && S.top() != '{' ) return false;

                S.pop();
            }
        }

        if( S.empty() ) return true;

        return false;
    }
};

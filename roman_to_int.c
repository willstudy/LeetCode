/*
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/

int romanToInt(char* s) {
    int result = 0;
    int index = 0;
    char *p = s;

    while( *p != '\0' )
    {
        p++;
        index++;
    }

    while( index > 0 )
    {
        if( (index - 2) < 0 )
        {
            switch( s[index -1] )
            {
                case 'I':
                        result++;
                        return result;
                case 'V':
                        result += 5;
                        return result;
                case 'X':
                        result += 10;
                        return result;
                case 'L':
                        result += 50;
                        return result;
                case 'C':
                        result += 100;
                        return result;
                 case 'D':
                        result += 500;
                        return result;
                case 'M':
                        result += 1000;
                        return result;
                default:
                        return 0;
            }
        }

        if( s[index - 1] == 'I' )
        {
            result++;
            index--;
        }
        else if( s[index -1] == 'V' )
        {
            if( s[index - 2] == 'I' )
            {
                result += 4;
                index -= 2;
            }
            else
            {
                result += 5;
                index++;
            }
        }
        else if( s[index -1] == 'X' )
        {
            if( s[index - 1] == 'I' )
            {
                result += 9;
                index -= 2;
            }
            else
            {
                result += 10;
                index--;
            }
        }
        else if( s[index -1] == 'L' )
        {
            if( s[index - 2] == 'X' )
            {
                result += 40;
                index -= 2;
            }
            else
            {
                result += 50;
                index--;
            }
        }
        else if( s[index - 1] == 'C' )
        {
            if( s[index - 2] == 'X' )
            {
                result += 90;
                index -= 2;
            }
            else
            {
                result += 100;
                index--;
            }
        }
        else if( s[index -1] == 'D' )
        {
            if( s[index - 2] == 'C' )
            {
                result += 400;
                index -= 2;
            }
            else
            {
                result += 500;
                index--;
            }
        }
        else if( s[index -1] == 'M' )
        {
            if( s[index - 2] == 'C' )
            {
                result += 900;
                index -= 2;
            }
            else
            {
                result += 1000;
                index--;
            }
        }
        else return 0;
    }

    return result;
}

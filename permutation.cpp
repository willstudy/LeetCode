/*
生成一串数字的全排列
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:

    void reverse( string & temp, int prev, int latter )
    {
        while( prev < latter ) {
            swap(temp[prev], temp[latter]);
            prev++;
            latter--;
        }
    }

    vector<string> Permutation(string str) {
	      vector<string> result;
        int size = str.size();

        if( size == 0 ) return result;

        string temp(str);
        sort( temp.begin(), temp.end() );
	      result.push_back(temp);

        while( true ) {

            int last = size - 1;
            int prev = last - 1;

            while( last ) {
            	while( temp[last] < temp[prev] && prev >= 0 ) {
                	prev--;
            	}
                if( prev >= 0 ) break;
                else if( last > 1 ){
                    last--;
                    prev = last - 1;
                }
                else {
			              return result;
		              }
            }

            swap( temp[prev], temp[last] );
            reverse( temp, prev+1, size-1);

            result.push_back(temp);
        }
    }
};


int main()
{
	string str = "abcde";
	Solution s;
	vector<string> result = s.Permutation(str);

	for( int i = 0; i < result.size(); i++ ) {
		cout << result[i] << endl;
	}

	return 0;
}

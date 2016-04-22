class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int size = array.size();
        int odd_start = 0;
        int even_start = 0;
        int flag = 0;

        for( int i = 0; i < size; i++ ) {
            if( array[i] & 1 ) {
                odd_start = i;
            }
            else if( flag == 0 ){
                even_start = i;
                flag = 1;
            }

            if( even_start < odd_start ) {
                int odd = array[odd_start];
                for( int j = odd_start; j > even_start; j-- ) {
                    array[j] = array[j-1];
                }
                array[even_start] = odd;
                even_start += 1;
            }
        }
    }
};

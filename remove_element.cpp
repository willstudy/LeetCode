/*
Given an array and a value, remove all instances of that value in place
and return the new length.The order of elements can be changed. It doesn't
matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if( size == 0 ) return 0;

        sort( nums.begin(), nums.end() );
        if( val < nums[0] || val > nums[size - 1] ) return size;

        int i = 0;
        int j = 0;

        for( i = 0; i < size; i++ )
        {
            if( nums[i] == val )
            {
                j = i + 1;
                while( nums[j] == val )
                {
                    j++;
                }
                break;
            }
        }
        while( j < size )
        {
            nums[i++] = nums[j++];
        }
        nums[i] = '\0';
        return i;
    }
};

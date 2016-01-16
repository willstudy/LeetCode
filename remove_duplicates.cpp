/*
Given a sorted array, remove the duplicates in place such that each element
appear only once and return the new length.Do not allocate extra space for
another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of
nums being 1 and 2 respectively. It doesn't matter what you leave beyond
the new length.
*/
/*
 * 前后比较，若不存在这个元素，即可加入该元素
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int length = 1;
        int i = 0;

        if( size <= 1 ) return size;

        for( i = 1; i < size; i++ )
        {
            if( nums[i] != nums[i-1] )
            {
                nums[length++] = nums[i];
            }
        }

        return length;
    }
};

/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n)
to hold additional elements from nums2. The number of elements initialized in nums1
and nums2 are m and n respectively.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        /* 倒着插进去 */
        while( i >=  0 && j >= 0 )
        {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        /* 因为用的是nums1数组存放最终结果,所以不用判断 i >= 0 这个条件了 */
        while( j >= 0 )
        {
            nums1[k--] = nums2[j--];
        }
    }
};

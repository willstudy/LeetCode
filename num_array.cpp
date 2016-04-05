/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

class NumArray {
public:
    NumArray(vector<int> &nums) : resultSum( nums.size() + 1, 0 )
    {
        partial_sum( nums.begin(), nums.end(), resultSum.begin() + 1 );
    }

    int sumRange(int i, int j)
    {
        return resultSum[j + 1] - resultSum[i];
    }
private:
    vector<int> resultSum;
};

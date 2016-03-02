/*
Given an array of integers and an integer k, find out whether there are
two distinct indices i and j in the array such that nums[i] = nums[j] and
the difference between i and j is at most k.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int size = nums.size();

        for(int i = 0; i < size; i++)
        {
            /* map中保存过此数，获取之前的index，与现在的index想比较，小于k则true */
            if( map.count(nums[i]) && ( i - map[nums[i]] <= k ) ) return true;

            map[nums[i]] = i;
        }

        return false;
    }
};

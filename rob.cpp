/*
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed, the only constraint stopping
you from robbing each of them is that adjacent houses have security system connected
and it will automatically contact the police if two adjacent houses were broken
into on the same night.

Given a list of non-negative integers representing the amount of money
of each house, determine the maximum amount of money you can rob tonight
without alerting the police.
*/
/*
 * 这一题可以使用动态规划求解。解决方法为：robber抢当前房子和不抢当前房子，要记住每次做出的选择，并根据
 * 当前这次选择，来选择下次是否抢该房子。
 */
class Solution {
public:
    int rob(vector<int>& nums) {

        int rob_prev_house = 0;        // 抢前一个房子
        int not_rob_prev_house = 0;    // 不抢前一个房子
        int size = nums.size();

        for( int i = 0; i < size; i++ )
        {
            int rob_current_house = not_rob_prev_house + nums[i];    // 抢当前的房子
            int not_rob_current_house = max( rob_prev_house, not_rob_prev_house );  // 不抢当前的房子

            rob_prev_house = rob_current_house;
            not_rob_prev_house = not_rob_current_house;
        }

        return max( rob_prev_house, not_rob_prev_house );
    }
};

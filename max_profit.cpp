/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and
sell one share of the stock), design an algorithm to find the maximum profit.
*/

/*
 * 用max_sofar记录当前最大的子数组，如果为0就重新计算
 * 当最大子数组的值为负数时，max_sofar应为很小的负数
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int size = prices.size();
        int max_profit = 0;
        int max_sofar = 0;

        for( int i = 1; i < size; i++ )
        {
            max_sofar += prices[i] - prices[i-1];
            max_sofar = max( 0, max_sofar );
            max_profit = max( max_profit, max_sofar );
        }

        return max_profit;
    }
};

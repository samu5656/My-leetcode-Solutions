/*
    Problem: Best Time to Buy and Sell Stock
    LeetCode: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
    Difficulty: Easy
    Topic: Array, Greedy
    Approach:
    - Track the minimum price seen so far
    - For each day, calculate profit if sold on that day
    - Keep updating the maximum profit
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Minimum price encountered so far (buy price)
        int minPrice = prices[0];

        // Variable to store maximum profit
        int maxProfit = 0;

        // Traverse prices from day 0 to last day
        for (int i = 0; i < n; i++) {

            // Update minimum price if a lower price is found
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            }
            else {
                // Calculate profit if sold on current day
                int profit = prices[i] - minPrice;

                // Update maximum profit
                maxProfit = max(maxProfit, profit);
            }
        }

        return maxProfit;
    }
};

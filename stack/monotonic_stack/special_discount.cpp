#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Problem: 1475. Final Prices With a Special Discount in a Shop
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 *
 * Algorithm:
 * Monotonic Stack
 *
 * Approach:
 * - Use a stack to store indices of prices whose discount has not
 *   been found yet.
 * - Initialize the result with the original prices.
 * - Traverse the prices from left to right.
 * - For the current price, check whether it can be used as a discount
 *   for the prices stored in the stack.
 * - While the current price is less than or equal to the price at the
 *   stack's top index, it is the first valid discount for that item.
 * - Update its final price by subtracting the current price.
 * - Pop the processed index from the stack.
 * - Push the current index into the stack for future discounts.
 * - Prices remaining in the stack have no valid discount, so their
 *   original prices remain unchanged.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        // Stack stores indices of prices waiting for a discount
        stack<int> st;

        // Initially, the result contains the original prices
        vector<int> result(prices.begin(), prices.end());

        // Traverse the prices from left to right
        for (int j = 0; j < prices.size(); j++) {

            // Current price is a valid discount for previous prices
            // if it is less than or equal to them
            while (!st.empty() && prices[st.top()] >= prices[j]) {

                // Get the index of the item receiving the discount
                int i = st.top();
                st.pop();

                // Apply the current price as the discount
                result[i] = prices[i] - prices[j];
            }

            // Store the current index for future discounts
            st.push(j);
        }

        return result;
    }
};
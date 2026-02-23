/*
    LeetCode: Best Time to Buy and Sell Stock II
    Difficulty: Easy
    Approach: Greedy

    Idea:
    Sum all positive price differences between consecutive days.
    This simulates buying before every rise and selling at the peak.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (size_t i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }

        return profit;
    }
};

int main() {
    Solution sol;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Profit: " << sol.maxProfit(prices1) << endl; // Expected: 7

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Profit: " << sol.maxProfit(prices2) << endl; // Expected: 4

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Profit: " << sol.maxProfit(prices3) << endl; // Expected: 0

    return 0;
}
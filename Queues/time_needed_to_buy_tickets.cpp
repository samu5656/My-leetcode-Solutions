#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * Problem: 2073. Time Needed to Buy Tickets
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/time-needed-to-buy-tickets/
 *
 * Algorithm:
 * Greedy Approach
 *
 * Approach:
 * - Instead of simulating the queue, calculate how many tickets
 *   each person can buy before person k finishes.
 * - The person at index k needs tickets[k] seconds to finish.
 * - For people before or at index k:
 *      They can buy at most tickets[k] tickets.
 * - For people after index k:
 *      They can buy at most tickets[k] - 1 tickets because the
 *      process stops as soon as person k buys their final ticket.
 * - Add the minimum of each person's required tickets and
 *   their respective limit.
 * - Return the total time.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {

        // Store the total time required
        int time = 0;

        // Calculate the time contributed by each person
        for (int i = 0; i < tickets.size(); i++) {

            // People before or at index k can buy up to tickets[k] tickets
            if (i <= k) {
                time += min(tickets[i], tickets[k]);
            }
            else {

                // People after index k get one fewer turn
                time += min(tickets[i], tickets[k] - 1);
            }
        }

        return time;
    }
};
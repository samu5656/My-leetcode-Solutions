#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/**
 * Problem: 950. Reveal Cards In Increasing Order
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/reveal-cards-in-increasing-order/
 *
 * Algorithm:
 * Sorting + Queue Simulation
 *
 * Approach:
 * - Sort the deck in ascending order.
 * - Create a queue containing all the original indices (0 to n-1).
 * - Create a result array to store the final deck arrangement.
 * - Traverse the sorted deck:
 *   - Place the current smallest card at the index present
 *     at the front of the queue.
 *   - Remove that index from the queue.
 *   - If indices remain, move the next index from the front
 *     to the back of the queue to simulate skipping one card.
 * - Return the result array.
 *
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {

        int n = deck.size();

        // Queue stores the original indices of the result array
        queue<int> q;

        // Stores the final deck arrangement
        vector<int> result(n);

        // Sort cards in increasing order
        sort(deck.begin(), deck.end());

        // Initialize the queue with all indices
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        // Simulate the reveal process
        for (int i = 0; i < n; i++) {

            // Place the current smallest card at the front index
            result[q.front()] = deck[i];
            q.pop();

            // Move the next index to the back to simulate skipping one card
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }

        return result;
    }
};
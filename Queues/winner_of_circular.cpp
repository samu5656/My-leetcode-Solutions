#include <iostream>
using namespace std;

/**
 * Problem: 1823. Find the Winner of the Circular Game
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
 *
 * Algorithm:
 * Josephus Problem (Mathematical Recurrence)
 *
 * Approach:
 * - Use the Josephus problem recurrence to find the winner's position.
 * - Initialize winner = 0, representing the winner's index
 *   in a circle containing one person (0-based indexing).
 * - Start from 2 people and gradually increase the circle size to n.
 * - For each circle size i, update the winner using:
 *
 *       winner = (winner + k) % i
 *
 * - After processing all n people, convert the 0-based index
 *   into a 1-based position by returning winner + 1.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int findTheWinner(int n, int k) {

        // Stores the winner's position using 0-based indexing
        int winner = 0;

        // Calculate the winner for circle sizes from 2 to n
        for (int i = 2; i <= n; i++) {

            // Josephus recurrence relation
            winner = (winner + k) % i;
        }

        // Convert the 0-based position to 1-based indexing
        return winner + 1;
    }
};
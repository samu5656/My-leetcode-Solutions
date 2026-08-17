#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * Problem: 1249. Minimum Remove to Make Valid Parentheses
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
 *
 * Algorithm:
 * Greedy + Balance Tracking
 *
 * Approach:
 * - Maintain a balance counter to track unmatched opening parentheses.
 * - Traverse the string from left to right.
 * - For '(':
 *      - Increase balance and keep the character.
 * - For ')':
 *      - If there is an unmatched '(', decrease balance and keep ')'.
 *      - Otherwise, skip ')' because it cannot be matched.
 * - After the first traversal, balance represents the number of unmatched
 *   opening parentheses.
 * - Traverse the result from right to left and remove the required number
 *   of unmatched '(' characters.
 * - Convert the remaining characters back into a string.
 *
 * Time Complexity: O(n²)
 * Space Complexity: O(n)
 */

class Solution {
public:
    string minRemoveToMakeValid(string s) {

        // Stores characters that are potentially part of the result
        vector<char> res;

        // Number of currently unmatched opening parentheses
        int balance = 0;

        // First pass: remove invalid closing parentheses
        for (char c : s) {

            // Opening parenthesis
            if (c == '(') {
                balance++;
                res.push_back(c);
            }

            // Closing parenthesis
            else if (c == ')') {

                // Keep ')' only if it has a matching '('
                if (balance > 0) {
                    balance--;
                    res.push_back(c);
                }
            }

            // Non-parenthesis characters are always valid
            else {
                res.push_back(c);
            }
        }

        // Second pass: remove unmatched opening parentheses
        for (int i = res.size() - 1; i >= 0 && balance > 0; i--) {

            if (res[i] == '(') {
                balance--;

                // Remove the unmatched '('
                res.erase(res.begin() + i);
            }
        }

        // Convert the resulting characters into a string
        return string(res.begin(), res.end());
    }
};
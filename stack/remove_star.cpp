#include <iostream>
#include <string>
using namespace std;

/**
 * Problem: 2390. Removing Stars From a String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/removing-stars-from-a-string/
 *
 * Algorithm:
 * Stack Simulation using String
 *
 * Approach:
 * - Use a string as a stack to store the characters that remain.
 * - Traverse the input string from left to right.
 * - If the current character is not '*', push it into the result.
 * - If the current character is '*', remove the most recently added
 *   character using pop_back().
 * - The problem guarantees that every '*' has a character to its left,
 *   so pop_back() is always valid.
 * - Return the resulting string after processing all characters.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    string removeStars(string s) {

        // String used as a stack to store remaining characters
        string ans;

        // Traverse each character of the input string
        for (char c : s) {

            // '*' removes the most recently added character
            if (c == '*') {
                ans.pop_back();
            }
            else {

                // Store the current character
                ans.push_back(c);
            }
        }

        // Return the final string
        return ans;
    }
};
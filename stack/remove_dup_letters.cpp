#include <iostream>
#include <string>
using namespace std;

/**
 * Problem: 316. Remove Duplicate Letters
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-duplicate-letters/
 *
 * Algorithm:
 * Greedy + Monotonic Stack
 *
 * Approach:
 * - Store the last occurrence of every character in the string.
 * - Use a string as a stack to build the smallest lexicographical result.
 * - Maintain an `inStack` array to ensure every character appears only once.
 * - For each character:
 *      1. Skip it if it is already present in the stack.
 *      2. While the top character is lexicographically larger than the
 *         current character and appears again later, remove it.
 *      3. Push the current character into the stack.
 * - The condition that the top character appears again later ensures that
 *   removing it is safe because we can add it again in the future.
 * - Return the stack as the final result.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    string removeDuplicateLetters(string s) {

        // Store the last occurrence index of each character
        int lastIndex[26] = {};

        for (int i = 0; i < s.size(); i++) {
            lastIndex[s[i] - 'a'] = i;
        }

        // Track whether a character is already in the stack
        bool inStack[26] = {};

        // String used as a stack to build the result
        string stack;

        // Traverse the input string
        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            // Skip the character if it is already in the result
            if (inStack[c - 'a']) {
                continue;
            }

            // Remove larger characters if they appear again later
            while (!stack.empty() &&
                   stack.back() > c &&
                   lastIndex[stack.back() - 'a'] > i) {

                // Mark the removed character as no longer present
                inStack[stack.back() - 'a'] = false;

                // Remove the character from the stack
                stack.pop_back();
            }

            // Add the current character to the stack
            stack.push_back(c);

            // Mark the character as present
            inStack[c - 'a'] = true;
        }

        // Return the smallest lexicographical result
        return stack;
    }
};
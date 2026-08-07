/**
 * Problem: 1614. Maximum Nesting Depth of the Parentheses
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 *
 * Algorithm:
 * Stack Traversal
 *
 * Approach:
 * - Push all characters of the string onto a stack.
 * - Traverse the stack from left to right by popping one character at a time.
 * - Maintain a counter to track the current nesting depth.
 * - Increment the counter when an opening parenthesis '(' is encountered.
 * - Decrement the counter when a closing parenthesis ')' is encountered.
 * - Update the maximum depth whenever the current depth increases.
 * - Return the maximum nesting depth.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {

        // Stack to store the characters of the string
        stack<char> stk;

        // Push all characters into the stack
        for (int i = s.length() - 1; i >= 0; i--) {
            stk.push(s[i]);
        }

        // Stores the current and maximum nesting depth
        int count = 0;
        int maxCount = 0;

        // Traverse the string using the stack
        for (int i = 0; i < s.length(); i++) {

            char c;

            // Get the current character
            if (!stk.empty()) {
                c = stk.top();
                stk.pop();
            }

            // Increase depth for opening parenthesis
            if (c == '(') {
                count++;
                maxCount = max(maxCount, count);
            }

            // Decrease depth for closing parenthesis
            else if (c == ')') {
                count--;
            }
        }

        // Return the maximum nesting depth
        return maxCount;
    }
};
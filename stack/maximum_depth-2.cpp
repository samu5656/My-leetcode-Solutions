/*
 * Problem: Maximum Nesting Depth of the Parentheses
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
 *
 * Algorithm:
 * Traverse the string and keep track of the current parenthesis depth.
 *
 * Approach:
 * - Increment depth whenever '(' is encountered.
 * - Update maxDepth with the maximum depth reached.
 * - Decrement depth whenever ')' is encountered.
 * - Return maxDepth.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;

        for (char c : s) {
            if (c == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if (c == ')') {
                depth--;
            }
        }

        return maxDepth;
    }
};
/**
 * Problem: 678. Valid Parenthesis String
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/valid-parenthesis-string/
 *
 * Algorithm:
 * Greedy Range Tracking
 *
 * Approach:
 * - Maintain two variables:
 *      1. low  -> Minimum possible number of unmatched '('.
 *      2. high -> Maximum possible number of unmatched '('.
 * - For '(':
 *      - Both low and high increase because it must be an opening parenthesis.
 * - For ')':
 *      - Both low and high decrease because it must close an opening parenthesis.
 * - For '*':
 *      - It can act as '(', ')' or an empty string.
 *      - Therefore, low decreases by 1 and high increases by 1.
 * - If high becomes negative, there are more ')' than can possibly be matched,
 *   so the string is invalid.
 * - low cannot be negative because the minimum number of unmatched opening
 *   parentheses cannot be less than zero.
 * - At the end, low == 0 means there is at least one valid interpretation
 *   of the string.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {

        int low = 0;
        int high = 0;

        for (char c : s) {

            if (c == '(') {
                low++;
                high++;
            }

            else if (c == ')') {
                low--;
                high--;
            }

            else {
                low--;
                high++;
            }

            if (high < 0) {
                return false;
            }

            low = max(low, 0);
        }

     return low == 0;
    }
};
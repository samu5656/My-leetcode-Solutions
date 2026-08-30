#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/**
 * Problem: 227. Basic Calculator II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/basic-calculator-ii/
 *
 * Algorithm:
 * One-Pass Evaluation with Operator Precedence
 *
 * Approach:
 * - Traverse the expression from left to right.
 * - Build the current number digit by digit.
 * - Maintain:
 *      1. result  -> Sum of numbers whose operations are already finalized.
 *      2. lastnum -> The most recent number, which may still be affected
 *                    by '*' or '/'.
 *      3. currnum -> The number currently being constructed.
 *      4. prevop  -> The operator before the current number.
 * - For '+' and '-', add the previous lastnum to result and store the
 *   current number as positive or negative in lastnum.
 * - For '*' and '/', immediately update lastnum because multiplication
 *   and division have higher precedence.
 * - At the end, add lastnum to result.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int calculate(string s) {

        // Stores the finalized result
        int result = 0;

        // Stores the most recent number that may need multiplication
        // or division before being added to the result
        int lastnum = 0;

        // Stores the current number being formed
        int currnum = 0;

        // Operator before the current number
        char prevop = '+';

        // Traverse the expression
        for (int i = 0; i < s.size(); i++) {

            char c = s[i];

            // Build the current number digit by digit
            if (isdigit(c)) {
                currnum = currnum * 10 + (c - '0');
            }

            // Process the current number when an operator is found
            // or when we reach the end of the expression
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {

                // Addition
                if (prevop == '+') {
                    result += lastnum;
                    lastnum = currnum;
                }

                // Subtraction
                else if (prevop == '-') {
                    result += lastnum;
                    lastnum = -currnum;
                }

                // Multiplication
                else if (prevop == '*') {
                    lastnum *= currnum;
                }

                // Division
                else if (prevop == '/') {
                    lastnum /= currnum;
                }

                // Reset the current number
                currnum = 0;

                // Store the current operator
                prevop = c;
            }
        }

        // Add the final pending number to the result
        return result + lastnum;
    }
};
#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

/**
 * Problem: 224. Basic Calculator
 * Difficulty: Hard
 * Link: https://leetcode.com/problems/basic-calculator/
 *
 * Algorithm:
 * Stack + Sign Tracking
 *
 * Approach:
 * - Traverse the expression from left to right.
 * - Build multi-digit numbers using `num`.
 * - Maintain `sign` to represent whether the current number should
 *   be added or subtracted.
 * - For '+' and '-', add the previous number to `result` and update
 *   the sign for the next number.
 * - When '(' is encountered:
 *      1. Store the current result on the stack.
 *      2. Store the current sign on the stack.
 *      3. Reset result and sign for the expression inside the brackets.
 * - When ')' is encountered:
 *      1. Complete the current calculation.
 *      2. Retrieve the sign before '('.
 *      3. Retrieve the result before '('.
 *      4. Apply the stored sign to the current result.
 *      5. Add it to the previous result.
 * - At the end, add the last number to the result.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int calculate(string s) {

        // Stores the current number being constructed
        long long num = 0;

        // Sign of the current number: +1 or -1
        int sign = 1;

        // Stores the result of the current expression
        int result = 0;

        // Stack stores results and signs before '('
        stack<int> st;

        // Traverse the expression
        for (char c : s) {

            // Build the current number digit by digit
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // Process addition
            else if (c == '+') {

                // Add the previous number using its sign
                result += sign * num;

                // Reset the current number
                num = 0;

                // Next number will be positive
                sign = 1;
            }

            // Process subtraction
            else if (c == '-') {

                // Add the previous number using its sign
                result += sign * num;

                // Reset the current number
                num = 0;

                // Next number will be negative
                sign = -1;
            }

            // Start of a parenthesized expression
            else if (c == '(') {

                // Store the result before '('
                st.push(result);

                // Store the sign before '('
                st.push(sign);

                // Start a fresh expression inside parentheses
                result = 0;
                sign = 1;
            }

            // End of a parenthesized expression
            else if (c == ')') {

                // Complete the current expression
                result += sign * num;

                // Reset the current number
                num = 0;

                // Retrieve the sign before '('
                int prevSign = st.top();
                st.pop();

                // Retrieve the result before '('
                int prevResult = st.top();
                st.pop();

                // Apply the sign that preceded the parentheses
                result *= prevSign;

                // Add the parenthesized result to the previous result
                result += prevResult;
            }
        }

        // Add the final number to the result
        return result + (sign * num);
    }
};
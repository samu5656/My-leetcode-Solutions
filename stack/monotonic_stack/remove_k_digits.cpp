#include <iostream>
#include <string>
using namespace std;

/**
 * Problem: 402. Remove K Digits
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/remove-k-digits/
 *
 * Algorithm:
 * Monotonic Stack
 *
 * Approach:
 * - Use a string as a stack to build the smallest possible number.
 * - Traverse each digit from left to right.
 * - If the current digit is smaller than the last digit in the stack,
 *   remove the larger digit while k > 0.
 * - This greedy approach keeps smaller digits toward the front,
 *   producing the smallest possible number.
 * - If k digits are still left after traversal, remove digits from
 *   the end of the stack.
 * - Remove leading zeroes while keeping at least one digit.
 * - If all digits are removed, return "0".
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    string removeKdigits(string num, int k) {

        // String used as a stack
        string stack = "";

        // Build the smallest possible number
        for (char a : num) {

            // Remove larger previous digits when possible
            while (!stack.empty() && k > 0 && stack.back() > a) {
                stack.pop_back();
                k--;
            }

            // Add the current digit
            stack.push_back(a);
        }

        // If removals are still remaining, remove from the end
        while (k > 0 && !stack.empty()) {
            stack.pop_back();
            k--;
        }

        // Remove leading zeroes, but keep at least one digit
        int start = 0;

        while (start < stack.size() - 1 && stack[start] == '0') {
            start++;
        }

        // If no digits remain, the result is zero
        if (stack.empty()) {
            return "0";
        }

        return stack.substr(start);
    }
};
#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

/**
 * Problem: 456. 132 Pattern
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/132-pattern/
 *
 * Algorithm:
 * Monotonic Stack
 *
 * Approach:
 * - Traverse the array from right to left.
 * - Maintain a decreasing stack to represent possible values for
 *   the "2" in the 132 pattern.
 * - Maintain `third` as the largest possible value for the "2"
 *   (the middle element of the pattern).
 * - For the current element nums[i]:
 *   - If nums[i] < third, then we have found:
 *       nums[i] < third < some element on the stack
 *     which forms a valid 132 pattern.
 *   - While nums[i] is greater than the stack top, pop elements
 *     because they can serve as the "2" value.
 *   - Update `third` with the largest popped value.
 * - Push the current element into the stack.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    bool find132pattern(vector<int>& nums) {

        int n = nums.size();

        // A 132 pattern requires at least three elements
        if (n < 3) {
            return false;
        }

        // Stores the possible "2" value in the pattern
        int third = INT_MIN;

        // Monotonic decreasing stack
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // nums[i] can act as the "1"
            // if it is smaller than the current "2" value
            if (nums[i] < third) {
                return true;
            }

            // Find values that can become the "2" of the pattern
            while (!st.empty() && nums[i] > st.top()) {

                // The popped value is a valid middle element
                third = max(third, st.top());

                st.pop();
            }

            // Store current value for future comparisons
            st.push(nums[i]);
        }

        return false;
    }
};
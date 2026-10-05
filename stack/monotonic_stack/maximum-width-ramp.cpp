#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

/**
 * Problem: 962. Maximum Width Ramp
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/maximum-width-ramp/
 *
 * Algorithm:
 * Monotonic Stack
 *
 * Approach:
 * - A ramp is a pair of indices (i, j) where i < j and nums[i] <= nums[j].
 * - First, build a decreasing monotonic stack of indices.
 * - An index is pushed only when its value is smaller than the value
 *   represented by the current stack top.
 * - These indices are potential starting points of the widest ramps.
 * - Traverse the array from right to left so that we always try to find
 *   the farthest possible ending index for each starting point.
 * - If nums[i] >= nums[st.top()], a valid ramp is found.
 * - Calculate its width and remove that starting index from the stack,
 *   since a farther right index cannot be found for it later.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {

        int max_width = 0;

        // Stack stores candidate starting indices
        stack<int> st;

        // Build a decreasing monotonic stack
        for (int i = 0; i < nums.size(); i++) {

            // Store only indices that can potentially start a ramp
            if (st.empty() || nums[st.top()] > nums[i]) {
                st.push(i);
            }
        }

        // Traverse from right to left to find the farthest endpoint
        for (int i = nums.size() - 1; i >= 0; i--) {

            // Check whether the current index can form a valid ramp
            while (!st.empty() && nums[i] >= nums[st.top()]) {

                // Update the maximum width
                max_width = max(max_width, i - st.top());

                // This starting index has found its farthest possible end
                st.pop();
            }
        }

        return max_width;
    }
};
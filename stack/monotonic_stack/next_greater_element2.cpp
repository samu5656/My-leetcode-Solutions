#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Problem: 503. Next Greater Element II
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/next-greater-element-ii/
 *
 * Algorithm:
 * Monotonic Stack
 *
 * Approach:
 * - The array is circular, so every element can see elements after it
 *   and then continue from the beginning of the array.
 * - To simulate this circular behavior, traverse the array twice
 *   using indices from 2*n-1 down to 0.
 * - Use i % n to convert the virtual index into a valid array index.
 * - Maintain a decreasing monotonic stack containing possible
 *   next greater elements.
 * - Remove all elements from the stack that are less than or equal
 *   to the current element.
 * - If the stack is not empty, its top is the next greater element.
 * - Push the current element into the stack for future elements.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();

        // Initialize all answers to -1
        vector<int> ans(n, -1);

        // Monotonic decreasing stack
        stack<int> st;

        // Traverse the circular array twice
        for (int i = 2 * n - 1; i >= 0; i--) {

            // Convert virtual index to actual array index
            int index = i % n;

            // Remove elements that cannot be the next greater element
            while (!st.empty() && st.top() <= nums[index]) {
                st.pop();
            }

            // The top is the nearest greater element
            if (!st.empty()) {
                ans[index] = st.top();
            }

            // Add current element for future comparisons
            st.push(nums[index]);
        }

        return ans;
    }
};
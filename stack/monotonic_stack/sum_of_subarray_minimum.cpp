#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Problem: 907. Sum of Subarray Minimums
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sum-of-subarray-minimums/
 *
 * Algorithm:
 * Monotonic Stack + Contribution Technique
 *
 * Approach:
 * - For each element, find the previous strictly smaller element
 *   and the next smaller-or-equal element.
 * - Use a monotonic increasing stack to calculate these boundaries.
 * - prevsmall[i] stores the index of the previous smaller element.
 * - nextsmall[i] stores the index of the next smaller-or-equal element.
 * - Calculate the number of subarrays in which arr[i] is the minimum:
 *      left = i - prevsmall[i]
 *      right = nextsmall[i] - i
 * - The contribution of arr[i] is left * right * arr[i].
 * - Add all contributions modulo 10^9 + 7.
 * - Using different comparison conditions for the two boundaries
 *   ensures duplicate minimum values are counted exactly once.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        const int MOD = 1e9 + 7;
        int n = arr.size();

        // Store the previous smaller and next smaller-or-equal indices
        vector<int> prevsmall(n, -1), nextsmall(n, n);

        // Monotonic stack stores indices
        stack<int> st;

        // Find the previous strictly smaller element for each index
        for (int i = 0; i < n; i++) {

            // Remove elements greater than or equal to the current value
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // Record the previous smaller element's index
            prevsmall[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        // Clear the stack before the reverse traversal
        while (!st.empty()) {
            st.pop();
        }

        // Find the next smaller-or-equal element for each index
        for (int i = n - 1; i >= 0; i--) {

            // Remove elements strictly greater than the current value
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // Record the next smaller-or-equal element's index
            nextsmall[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        // Calculate the sum using each element's contribution
        int sum = 0;

        for (int i = 0; i < n; i++) {

            // Number of choices for the subarray's left boundary
            int left = i - prevsmall[i];

            // Number of choices for the subarray's right boundary
            int right = nextsmall[i] - i;

            // Add the contribution of arr[i], using long long to prevent overflow
            sum = (sum + (long long)left * right * arr[i]) % MOD;
        }

        return sum;
    }
};
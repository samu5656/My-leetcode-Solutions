#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * Problem: 2104. Sum of Subarray Ranges
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/sum-of-subarray-ranges/
 *
 * Algorithm:
 * Monotonic Stack + Contribution Technique
 *
 * Approach:
 * - The range of a subarray is its maximum minus its minimum.
 * - Instead of calculating every subarray individually, calculate:
 *      Sum of all subarray maximums
 *      Sum of all subarray minimums
 * - The final answer is:
 *      Sum of Maximums - Sum of Minimums
 *
 * SumOfSubMax():
 * - Use a monotonic increasing stack of indices.
 * - When the current element is greater than or equal to the
 *   stack's top element, pop the index.
 * - The popped element becomes the maximum of several subarrays.
 * - Calculate its contribution using the number of possible
 *   left and right boundaries.
 *
 * SumOfSubMin():
 * - Use a monotonic decreasing stack of indices.
 * - When the current element is less than or equal to the
 *   stack's top element, pop the index.
 * - Calculate the contribution of the popped element as a minimum.
 *
 * - Use INT_MAX and INT_MIN as sentinels to process remaining
 *   elements in the stacks after traversal.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        // Calculate the sum of all subarray maximums
        long long max = SumOfSubMax(n, nums);

        // Calculate the sum of all subarray minimums
        long long min = SumOfSubMin(n, nums);

        // Range = Maximum - Minimum
        return max - min;
    }

    // Calculate the sum of subarray maximums
    long long SumOfSubMax(int n, vector<int>& nums) {

        long long sum = 0;

        // Stack stores indices of potential maximum elements
        vector<int> stk;

        // Traverse the array and use INT_MAX as the final sentinel
        for (int i = 0; i <= n; i++) {

            int curr = (i == n) ? INT_MAX : nums[i];

            // Pop elements that are smaller than or equal to current
            while (!stk.empty() && nums[stk.back()] <= curr) {

                // Index of the element being processed
                int mid = stk.back();
                stk.pop_back();

                // Find the previous greater element
                int lb = stk.empty() ? -1 : stk.back();

                // Current index acts as the next greater-or-equal boundary
                int rb = i;

                // Number of possible left and right boundaries
                int lc = mid - lb;
                int rc = rb - mid;

                // Add the contribution of nums[mid] as a subarray maximum
                sum += (long long)lc * rc * nums[mid];
            }

            // Push the current index
            if (i < n) {
                stk.push_back(i);
            }
        }

        return sum;
    }

    // Calculate the sum of subarray minimums
    long long SumOfSubMin(int n, vector<int>& nums) {

        long long sum = 0;

        // Stack stores indices of potential minimum elements
        vector<int> stk;

        // Traverse the array and use INT_MIN as the final sentinel
        for (int i = 0; i <= n; i++) {

            int curr = (i == n) ? INT_MIN : nums[i];

            // Pop elements that are greater than or equal to current
            while (!stk.empty() && nums[stk.back()] >= curr) {

                // Index of the element being processed
                int mid = stk.back();
                stk.pop_back();

                // Find the previous smaller element
                int lb = stk.empty() ? -1 : stk.back();

                // Current index acts as the next smaller-or-equal boundary
                int rb = i;

                // Number of possible left and right boundaries
                int lc = mid - lb;
                int rc = rb - mid;

                // Add the contribution of nums[mid] as a subarray minimum
                sum += (long long)lc * rc * nums[mid];
            }

            // Push the current index
            if (i < n) {
                stk.push_back(i);
            }
        }

        return sum;
    }
};
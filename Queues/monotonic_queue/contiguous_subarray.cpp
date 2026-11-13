#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 * Problem: 2762. Continuous Subarrays
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/continuous-subarrays/
 *
 * Algorithm:
 * Sliding Window + Monotonic Deques
 *
 * Approach:
 * - Use a sliding window to maintain valid continuous subarrays.
 * - Maintain two monotonic deques:
 *   - maxdequeue stores indices in decreasing order of values.
 *   - mindequeue stores indices in increasing order of values.
 * - Traverse the array using the right pointer.
 * - For every new element:
 *   - Remove smaller or equal elements from the back of maxdequeue.
 *   - Remove greater or equal elements from the back of mindequeue.
 *   - Insert the current index into both deques.
 * - If the difference between the maximum and minimum values
 *   in the current window exceeds 2, move the left pointer forward.
 * - Remove outdated indices from the fronts of the deques.
 * - Every window ending at right and starting between left and right
 *   is valid.
 * - Add (right - left + 1) to the total count.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {

        // Stores the total number of valid subarrays
        long long count = 0;

        // Left boundary of the sliding window
        int left = 0;

        // Deque maintains indices in decreasing order of values
        deque<int> maxdequeue;

        // Deque maintains indices in increasing order of values
        deque<int> mindequeue;

        // Expand the sliding window using the right pointer
        for (int right = 0; right < nums.size(); right++) {

            // Remove smaller or equal elements from the maximum deque
            while (!maxdequeue.empty() &&
                   nums[maxdequeue.back()] <= nums[right]) {
                maxdequeue.pop_back();
            }

            // Insert the current index into the maximum deque
            maxdequeue.push_back(right);

            // Remove greater or equal elements from the minimum deque
            while (!mindequeue.empty() &&
                   nums[mindequeue.back()] >= nums[right]) {
                mindequeue.pop_back();
            }

            // Insert the current index into the minimum deque
            mindequeue.push_back(right);

            // Shrink the window until max - min is at most 2
            while (nums[maxdequeue.front()] - nums[mindequeue.front()] > 2) {

                left++;

                // Remove indices that are outside the current window
                if (maxdequeue.front() < left) {
                    maxdequeue.pop_front();
                }

                if (mindequeue.front() < left) {
                    mindequeue.pop_front();
                }
            }

            // Count all valid subarrays ending at the current right index
            count += right - left + 1;
        }

        return count;
    }
};
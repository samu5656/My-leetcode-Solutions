#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * Problem: 769. Max Chunks To Make Sorted
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/max-chunks-to-make-sorted/
 *
 * Algorithm:
 * Prefix Maximum
 *
 * Approach:
 * - Maintain the maximum element encountered so far using max_num.
 * - Traverse the array from left to right.
 * - Update max_num with the maximum of its current value and arr[i].
 * - If max_num == i, all elements in the current prefix belong
 *   to their correct positions when sorted.
 * - Therefore, a chunk can end at index i, so increment chunks.
 * - Return the total number of chunks.
 *
 * Note:
 * - This approach works because the problem guarantees that arr
 *   is a permutation of integers from 0 to n - 1.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        // Track the maximum value in the current prefix
        int max_num = INT_MIN;

        // Count the number of valid chunks
        int chunks = 0;

        // Traverse the array
        for (int i = 0; i < arr.size(); i++) {

            // Update the prefix maximum
            max_num = max(max_num, arr[i]);

            // A chunk can end when the maximum equals the index
            if (max_num == i) {
                chunks++;
            }
        }

        return chunks;
    }
};
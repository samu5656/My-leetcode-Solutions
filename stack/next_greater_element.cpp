#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

/**
 * Problem: 496. Next Greater Element I
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/next-greater-element-i/
 *
 * Algorithm:
 * Monotonic Stack + Hash Map
 *
 * Approach:
 * - Traverse nums2 from left to right.
 * - Use a stack to store elements whose next greater element has not
 *   been found yet.
 * - For every current element, compare it with the top of the stack.
 * - If the current element is greater, it is the next greater element
 *   for the stack's top element.
 * - Keep popping smaller elements and store their next greater element
 *   in a hash map.
 * - Push the current element onto the stack.
 * - Finally, traverse nums1 and use the hash map to find the next greater
 *   element for each value.
 * - If no greater element exists, return -1.
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(n)
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Maps each element to its next greater element
        unordered_map<int, int> map;

        // Monotonic decreasing stack
        stack<int> st;

        // Stores the final answers for nums1
        vector<int> result;

        // Find the next greater element for every value in nums2
        for (int nums : nums2) {

            // Current element is the next greater element
            // for all smaller elements at the top of the stack
            while (!st.empty() && st.top() < nums) {

                map[st.top()] = nums;
                st.pop();
            }

            // Store the current element for future comparisons
            st.push(nums);
        }

        // Find the answers for elements present in nums1
        for (int nums : nums1) {

            // If a next greater element exists, use it;
            // otherwise return -1
            result.push_back(map.count(nums) ? map[nums] : -1);
        }

        // Return the result
        return result;
    }
};
/*
===========================================================
LeetCode 152. Maximum Product Subarray
===========================================================

Problem:
Given an integer array nums, find a contiguous non-empty subarray
that has the largest product, and return the product.

Approach:
- Traverse the array from both left to right (prefix) and
  right to left (suffix).
- Reset the running product to 1 whenever it becomes 0,
  since a zero splits the array into independent segments.
- Scanning from both directions ensures that cases with an
  odd number of negative numbers are handled correctly.
- Keep updating the maximum product encountered.

Time Complexity : O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 0, suffix = 0, result = nums[0];
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            prefix = (prefix == 0 ? 1 : prefix) * nums[i];
            suffix = (suffix == 0 ? 1 : suffix) * nums[n - 1 - i];

            result = max(result, max(prefix, suffix));
        }

        return result;
    }
};
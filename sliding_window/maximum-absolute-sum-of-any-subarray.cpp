/*
===========================================================
LeetCode 1749. Maximum Absolute Sum of Any Subarray
===========================================================

Problem:
Given an integer array nums, return the maximum absolute sum of any
(non-empty) subarray.

Approach:
- Use Prefix Sum.
- The absolute sum of any subarray is the absolute difference between
  two prefix sums.
- Track the minimum and maximum prefix sums while traversing the array.
- The answer is the difference between the maximum and minimum prefix sums.

Time Complexity : O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum = 0;
        int maxsum = 0;
        int prefixsum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefixsum += nums[i];
            minsum = min(minsum, prefixsum);
            maxsum = max(maxsum, prefixsum);
        }

        return maxsum - minsum;
    }
};
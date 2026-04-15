/*
------------------------------------------------------------
Problem: Increasing Triplet Subsequence
Platform: LeetCode
Approach: Greedy (Two Variables)
Time Complexity: O(n)
Space Complexity: O(1)
------------------------------------------------------------

Description:
Given an integer array nums, return true if there exists a
triplet (i, j, k) such that:
    i < j < k  AND  nums[i] < nums[j] < nums[k]

Otherwise, return false.

------------------------------------------------------------
Approach Explanation:

We maintain two variables:
1. first  -> smallest value seen so far
2. second -> second smallest value greater than first

Traverse the array:
- If current element <= first → update first
- Else if current element <= second → update second
- Else → we found a number greater than both → triplet exists

------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;   // smallest element
        int second = INT_MAX;  // second smallest element

        for (int num : nums) {
            // Update smallest value
            if (num <= first) {
                first = num;
            }
            // Update second smallest value
            else if (num <= second) {
                second = num;
            }
            // Found third element greater than both
            else {
                return true;
            }
        }

        // No increasing triplet found
        return false;
    }
};
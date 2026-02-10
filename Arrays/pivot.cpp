/*
------------------------------------------------------------
Title: Find Pivot Index
Platform: LeetCode
Link: https://leetcode.com/problems/find-pivot-index/

Problem Description:
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to
the left of the index is equal to the sum of all the numbers strictly to
the right of the index.

If the index is on the left edge of the array, then the left sum is 0.
If the index is on the right edge of the array, then the right sum is 0.

Return the leftmost pivot index. If no such index exists, return -1.

------------------------------------------------------------
Approach:
1. Compute the total sum of the array.
2. Maintain a running prefix sum called leftSum.
3. For each index i:
      rightSum = totalSum - leftSum - nums[i]
4. If leftSum == rightSum, return i.
5. Update leftSum by adding nums[i].

------------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

------------------------------------------------------------
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;

        // Calculate total sum of the array
        for (int x : nums) {
            totalSum += x;
        }

        int leftSum = 0;

        // Traverse and check pivot condition
        for (int i = 0; i < nums.size(); ++i) {
            int rightSum = totalSum - leftSum - nums[i];

            if (leftSum == rightSum) {
                return i;
            }

            leftSum += nums[i];
        }
    }
};

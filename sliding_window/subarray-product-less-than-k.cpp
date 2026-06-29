#include<bits/stdc++.h>
using namespace std;

// ======================================================
// Problem Title: Subarray Product Less Than K
// ======================================================

// Problem Description:
// Given an array of positive integers nums and an integer k, return the number
// of contiguous subarrays where the product of all the elements is strictly
// less than k.
//
// Approach:
// Use the sliding window technique to maintain a window whose product is less
// than k. Expand the window by moving the right pointer and multiply the new
// element into the current product. If the product becomes greater than or
// equal to k, shrink the window from the left until the product becomes less
// than k again. For each valid window ending at the current right index,
// all subarrays ending at 'right' and starting from 'left' to 'right' are
// valid, contributing (right - left + 1) to the answer.
// If k <= 1, no valid non-empty subarray can exist since all elements are
// positive, so return 0 immediately.

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        if (k <= 1) return 0;

        int left = 0, product = 1, count = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            product *= nums[right];

            while (product >= k)
            {
                product = product / nums[left];
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }
};

// ======================================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
// ======================================================
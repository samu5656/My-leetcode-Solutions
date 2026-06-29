#include<bits/stdc++.h>
using namespace std;

// ======================================================
// Problem Title: Frequency of the Most Frequent Element
// ======================================================

// Problem Description:
// Given an integer array nums and an integer k, you can perform at most k
// increment operations. In one operation, you may increase any element by 1.
// Return the maximum possible frequency of the most frequent element after
// performing at most k operations.
//
// Approach:
// Sort the array and use a sliding window. The rightmost element of the window
// is treated as the target value since only increment operations are allowed.
// Maintain the sum of the current window. The number of operations required to
// make every element in the window equal to nums[right] is:
//
//     operations = nums[right] * windowSize - windowSum
//
// If the required operations exceed k, shrink the window from the left until
// it becomes valid again. The maximum valid window size is the answer.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {

        sort(nums.begin(), nums.end());

        int left = 0, length = 0, operations = 0;
        long long windowsum = 0;

        for (int right = 0; right < nums.size(); right++) {
            windowsum += nums[right];

            while ((long long)nums[right] * (right - left + 1) - windowsum > k) {
                windowsum -= nums[left];
                left++;
            }

            length = max(length, right - left + 1);
        }

        return length;
    }
};

// ======================================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
// ======================================================
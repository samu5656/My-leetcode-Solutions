#include <bits/stdc++.h>
using namespace std;

/*
Problem: Maximum Sum Circular Subarray

Approach:
1. Use Kadane's Algorithm to find the maximum subarray sum.
2. Use Kadane's Algorithm to find the minimum subarray sum.
3. Calculate the total sum of the array.
4. The answer is the maximum of:
   - Normal maximum subarray sum.
   - Circular maximum subarray sum = total sum - minimum subarray sum.
5. If all elements are negative, return the maximum subarray sum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currmin = 0, currmax = 0;
        int globalmin = nums[0], globalmax = nums[0];
        int total = 0;

        for (int i = 0; i < nums.size(); i++) {
            currmin = min(nums[i], currmin + nums[i]);
            currmax = max(nums[i], currmax + nums[i]);
            total += nums[i];

            globalmin = min(globalmin, currmin);
            globalmax = max(globalmax, currmax);
        }

        return (globalmax < 0) ? globalmax : max(globalmax, total - globalmin);
    }
};
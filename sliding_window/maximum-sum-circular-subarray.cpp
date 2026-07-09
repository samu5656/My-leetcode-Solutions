#include <bits/stdc++.h>
using namespace std;

/*
Problem: Maximum Sum Circular Subarray

Approach:
1. Use Kadane's Algorithm to find the maximum subarray sum.
2. Use Kadane's Algorithm to find the minimum subarray sum.
3. Compute the total array sum.
4. The answer is the maximum of:
   - Normal maximum subarray sum.
   - Circular maximum subarray sum = totalSum - minimumSubarraySum.
5. If all elements are negative, return the normal maximum subarray sum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
    public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int currMax = 0, currMin = 0;
        int globalMax = INT_MIN, globalMin = INT_MAX;

        for (int num : nums) {
            currMax = max(num, currMax + num);
            globalMax = max(globalMax, currMax);

            currMin = min(num, currMin + num);
            globalMin = min(globalMin, currMin);

            total += num;
        }

        if (globalMax < 0)
            return globalMax;

        return max(globalMax, total - globalMin);
    }
};
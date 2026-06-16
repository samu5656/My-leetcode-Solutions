#include<bits/stdc++.h>
using namespace std;
/*
    Problem: Continuous Subarray Sum
    Link: https://leetcode.com/problems/continuous-subarray-sum/

    Approach:
    - Use prefix sum and remainder concept.
    - If two prefix sums have the same remainder when divided by k,
      the sum of elements between them is divisible by k.
    - Store the first occurrence index of each remainder.
    - If the same remainder appears again and the subarray length is at least 2,
      return true.

    Time Complexity: O(n)
    Space Complexity: O(min(n, k))
*/

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1;

        int prefix_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];
            int remainder = prefix_sum % k;

            if (remainderIndex.count(remainder)) {
                if (i - remainderIndex[remainder] >= 2) {
                    return true;
                }
            } else {
                remainderIndex[remainder] = i;
            }
        }

        return false;
    }
};
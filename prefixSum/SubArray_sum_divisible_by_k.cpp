/*
Problem: Subarray Sums Divisible by K
Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/

Approach:
- Use prefix sums and remainder frequency counting.
- If two prefix sums have the same remainder when divided by k,
  the subarray between them has a sum divisible by k.
- Normalize negative remainders using:
  ((prefix_sum % k) + k) % k

Time Complexity: O(n)
Space Complexity: O(k)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0, prefix_sum = 0;
        unordered_map<int, int> prefix_count;

        prefix_count[0] = 1;

        for (int num : nums) {
            prefix_sum += num;

            int remainder = ((prefix_sum % k) + k) % k;

            count += prefix_count[remainder];
            prefix_count[remainder]++;
        }

        return count;
    }
};
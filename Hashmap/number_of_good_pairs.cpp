/*
LeetCode 1512. Number of Good Pairs
Link: https://leetcode.com/problems/number-of-good-pairs/

Approach:
Use a frequency array to count occurrences of each number.

For every number:
- freq[num] tells how many times this number has already appeared.
- Each previous occurrence forms a good pair with the current number.
- Add freq[num] to count, then increase its frequency.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int freq[101] = {0};
        int count = 0;

        for(int num : nums)
        {
            count += freq[num];
            freq[num]++;
        }

        return count;
    }
};
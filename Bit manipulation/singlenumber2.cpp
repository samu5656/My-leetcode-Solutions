/*
    LeetCode 137 - Single Number II
    Link: https://leetcode.com/problems/single-number-ii/

    Approach:
    ----------
    Use two bitmasks:
    - ones -> stores bits appearing once (mod 3)
    - twos -> stores bits appearing twice (mod 3)

    State Transition for each bit:
    0 occurrence -> ones -> twos -> removed -> repeat

    Time Complexity  : O(n)
    Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ones = 0;
        int twos = 0;

        for (int num : nums) {

            // Add bits to ones if not already in twos
            ones = (ones ^ num) & ~twos;

            // Add bits to twos if not already in ones
            twos = (twos ^ num) & ~ones;
        }

        // Remaining bits in ones are the unique number
        return ones;
    }
};
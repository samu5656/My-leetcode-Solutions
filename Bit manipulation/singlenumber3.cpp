/*
    LeetCode 260 - Single Number III
    Link: https://leetcode.com/problems/single-number-iii/

    Approach:
    ----------
    1. XOR all elements.
       Duplicate numbers cancel each other.

       xorall = a ^ b
       where a and b are the two unique numbers.

    2. Find the rightmost set bit:
       bit = xorall & (-xorall)

       This bit is different in a and b.

    3. Divide numbers into two groups:
       - numbers having that bit set
       - numbers not having that bit set

    4. XOR one group to get first unique number.
       Second unique number:
       xorall ^ x

    Time Complexity  : O(n)
    Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorall = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            xorall ^= nums[i];
        }

        long long bit = xorall & (-xorall);

        int x = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] & bit)
            {
                x ^= nums[i];
            }
        }

        return {x, (int)xorall ^ x};
    }
};
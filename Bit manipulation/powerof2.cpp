/*
LeetCode 231 - Power of Two
Link: https://leetcode.com/problems/power-of-two/

Approach:
A power of 2 contains exactly one set bit in binary.
For such numbers:

    n & (n - 1) == 0

Example:
8  -> 1000
7  -> 0111
--------------
      0000

Time Complexity : O(1)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if (n <= 0)
            return false;

        return (n & (n - 1)) == 0;
    }
};
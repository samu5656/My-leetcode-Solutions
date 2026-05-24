/*
    LeetCode 190 - Reverse Bits
    Link: https://leetcode.com/problems/reverse-bits/

    Approach:
    Reverse bits one by one using bit manipulation.

    Logic:
    1. Extract the last bit using (n & 1)
    2. Shift result left by 1
    3. Add extracted bit to result
    4. Shift n right by 1
    5. Repeat 32 times

    Example:
    n = 00000000000000000000000000001011

    Iteration Process:
    Extract bits from right to left
    and build reversed number from left to right.

    Time Complexity: O(32) -> O(1)
    Space Complexity: O(1)
*/

#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:

    uint32_t reverseBits(uint32_t n) {

        uint32_t res = 0;

        for (int i = 0; i < 32; i++) {

            res = (res << 1) | (n & 1);

            n >>= 1;
        }

        return res;
    }
};
/*
    LeetCode 461 - Hamming Distance
    Link: https://leetcode.com/problems/hamming-distance/

    Approach:
    - XOR (^) gives differing bits between x and y.
    - Count the number of set bits in the XOR result
      using Brian Kernighan’s Algorithm.

    Brian Kernighan’s Logic:
    res = res & (res - 1)

    This removes the rightmost set bit in each iteration.

    Example:
    x = 1  -> 0001
    y = 4  -> 0100

    x ^ y = 0101

    Number of set bits = 2
    Hence Hamming Distance = 2

    Time Complexity: O(number of set bits)
    Space Complexity: O(1)
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {

        int distance = 0;

        int res = x ^ y;

        while (res != 0) {
            res = res & (res - 1);
            distance++;
        }

        return distance;
    }
};
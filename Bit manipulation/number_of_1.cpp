/*
    LeetCode 191 - Number of 1 Bits
    Link: https://leetcode.com/problems/number-of-1-bits/

    Optimal Approach: Brian Kernighan’s Algorithm

    Idea:
    - The expression (n & (n - 1)) removes the rightmost set bit.
    - Count how many times we can perform this operation until n becomes 0.

    Example:
    n = 101100
    n-1 = 101011
    ----------------
    n&(n-1) = 101000

    Time Complexity: O(number of set bits)
    Space Complexity: O(1)
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while (n) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};
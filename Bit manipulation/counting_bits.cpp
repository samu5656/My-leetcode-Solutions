/*
    LeetCode 338 - Counting Bits
    Link: https://leetcode.com/problems/counting-bits/

    Optimal Dynamic Programming Approach

    Logic:
    res[i] = res[i / 2] + (i % 2)

    Explanation:
    - Dividing a number by 2 removes the last binary bit.
    - (i % 2) tells whether the removed last bit was 0 or 1.
    - So:
          set bits in i
        = set bits in i/2
        + last bit

    Example:
    i = 13 -> 1101

    i/2 = 6 -> 110
    last bit = 1

    res[13] = res[6] + 1
            = 2 + 1
            = 3

    Time Complexity: O(n)
    Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> res(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            res[i] = res[i / 2] + (i % 2);
        }

        return res;
    }
};
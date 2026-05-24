/*
    LeetCode 201 - Bitwise AND of Numbers Range
    Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/

    Optimal Approach:
    Find the common prefix of left and right.

    Logic:
    - Continuously right shift both numbers
      until they become equal.
    - Count how many shifts were performed.
    - Left shift the common prefix back
      to its original position.

    Why This Works:
    - In the range [left, right],
      changing bits become 0 after AND operation.
    - Only the common leading bits remain unchanged.

    Example:
    left  = 5  -> 0101
    right = 7  -> 0111

    Shift 1:
    0010
    0011

    Shift 2:
    0001
    0001

    Common prefix = 1

    Restore shifted bits:
    1 << 2 = 4

    Answer = 4

    Time Complexity: O(32) -> O(1)
    Space Complexity: O(1)
*/

#include <iostream>

using namespace std;

class Solution {
public:

    int rangeBitwiseAnd(int left, int right) {

        int shifts = 0;

        while (left != right) {
            left >>= 1;
            right >>= 1;
            shifts++;
        }

        return left << shifts;
    }
};
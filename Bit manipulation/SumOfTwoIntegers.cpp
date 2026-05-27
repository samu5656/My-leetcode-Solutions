/*
LeetCode Problem: 371. Sum of Two Integers
Link: https://leetcode.com/problems/sum-of-two-integers/

Approach:
Use bit manipulation to add two integers without using + or -.
XOR (^) gives the sum without carry.
AND (&) finds the carry bits.
Left shift (<< 1) moves the carry to the next position.
Repeat until no carry remains.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
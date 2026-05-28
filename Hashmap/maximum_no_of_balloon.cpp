/*
LeetCode 1189. Maximum Number of Balloons
Link: https://leetcode.com/problems/maximum-number-of-balloons/

Approach:
Count the frequency of every character in the string.
The word "balloon" requires:
b -> 1
a -> 1
l -> 2
o -> 2
n -> 1

The maximum number of times we can form "balloon"
depends on the minimum available required character count.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count[26] = {0};

        // Count frequency of each character
        for (char c : text) {
            count[c - 'a']++;
        }

        int result = count['b' - 'a'];

        result = min(result, count['a' - 'a']);
        result = min(result, count['l' - 'a'] / 2);
        result = min(result, count['o' - 'a'] / 2);
        result = min(result, count['n' - 'a']);

        return result;
    }
};
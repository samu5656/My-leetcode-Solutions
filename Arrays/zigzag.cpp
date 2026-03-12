// Problem: Zigzag Conversion
// Link: https://leetcode.com/problems/zigzag-conversion/
// Approach: Simulate the zigzag pattern by storing characters row by row.
// Traverse the string while moving down and up across rows.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.length()) {
            return s;
        }

        vector<string> rows(numRows);
        int curr = 0;
        bool down = false;

        for (char c : s) {
            rows[curr] += c;

            if (curr == 0 || curr == numRows - 1) {
                down = !down;
            }

            curr += down ? 1 : -1;
        }

        string res;
        for (string row : rows) {
            res += row;
        }

        return res;
    }
};
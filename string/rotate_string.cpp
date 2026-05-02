// LeetCode: Rotate String
// Approach: Try all rotations of s using modulo indexing and compare with goal. 
// For each starting index k, check if rotated string matches goal.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        int n = s.length();

        for (int k = 0; k < n; k++) {
            bool match = true;

            for (int j = 0; j < n; j++) {
                if (s[(k + j) % n] != goal[j]) {
                    match = false;
                    break;
                }
            }

            if (match)
                return true;
        }

        return false;
    }
};
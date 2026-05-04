#include <bits/stdc++.h>
using namespace std;
// LeetCode 161: One Edit Distance
// https://leetcode.com/problems/one-edit-distance/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length();
        int m = t.length();

        if (abs(n - m) > 1) return false;

        // Ensure s is shorter or equal
        if (n > m) return isOneEditDistance(t, s);

        // Same length → replacement case
        if (n == m) {
            int mismatch = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != t[i]) {
                    mismatch++;
                    if (mismatch > 1) return false;
                }
            }
            return mismatch == 1;
        }

        // Length differs by 1 → insert/delete case
        int i = 0, j = 0;
        int edit = 0;

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                edit++;
                if (edit > 1) return false;
                j++; // skip in longer string
            }
        }

        return true;
    }
};
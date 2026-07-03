#include <bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: 76. Minimum Window Substring
Link: https://leetcode.com/problems/minimum-window-substring/

Description:
Given two strings s and t of lengths m and n respectively, return the
minimum window substring of s such that every character in t (including
duplicates) is included in the window. If there is no such substring,
return an empty string.
===========================================================
*/

/*
===========================================================
Approach:
- Use the Sliding Window technique with two pointers.
- Store the frequency of each character in t.
- Expand the right pointer to include characters into the window.
- Once all required characters are matched, shrink the window from the
  left to find the minimum valid window.
- Keep track of the smallest valid window found during the process.
===========================================================
*/

/*
===========================================================
Time Complexity: O(|S| + |T|)
- Each character is visited at most twice (once by the right pointer and
  once by the left pointer).

Space Complexity: O(|T|)
- Hash map stores the frequency of characters present in t.
===========================================================
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, minindex = INT_MAX, count = 0, sIndex = -1;

        if (s.length() < t.length()) return "";

        unordered_map<char, int> freq;
        for (int i = 0; i < t.length(); i++) {
            freq[t[i]]++;
        }

        for (int r = 0; r < s.length(); r++) {
            if (freq[s[r]] > 0) count++;
            freq[s[r]]--;

            while (count == t.length()) {
                if (r - l + 1 < minindex) {
                    minindex = r - l + 1;
                    sIndex = l;
                }

                freq[s[l]]++;
                if (freq[s[l]] > 0) count--;
                l++;
            }
        }

        return sIndex == -1 ? "" : s.substr(sIndex, minindex);
    }
};
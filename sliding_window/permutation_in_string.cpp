/*
    Problem: Permutation in String
    LeetCode: 567

    Approach:
    - Use a sliding window of size s1.length().
    - Maintain frequency counts for:
        1. s1 (s1Count)
        2. Current window in s2 (windowCount)
    - Keep track of how many character frequencies match using
      a variable 'matches'.
    - If matches becomes 26, a permutation of s1 exists in s2.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.length();
        int s2len = s2.length();

        if (s2len < s1len)
            return false;

        vector<int> s1Count(26, 0);
        vector<int> windowCount(26, 0);

        // Build frequency arrays for s1 and first window of s2
        for (int i = 0; i < s1len; i++) {
            s1Count[s1[i] - 'a']++;
            windowCount[s2[i] - 'a']++;
        }

        // Count initial matches
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (s1Count[i] == windowCount[i])
                matches++;
        }

        // Check first window
        if (matches == 26)
            return true;

        // Slide the window
        for (int i = s1len; i < s2len; i++) {

            int inChar = s2[i] - 'a';
            int outChar = s2[i - s1len] - 'a';

            // Add incoming character
            windowCount[inChar]++;

            if (windowCount[inChar] == s1Count[inChar])
                matches++;
            else if (windowCount[inChar] == s1Count[inChar] + 1)
                matches--;

            // Remove outgoing character
            windowCount[outChar]--;

            if (windowCount[outChar] == s1Count[outChar])
                matches++;
            else if (windowCount[outChar] == s1Count[outChar] - 1)
                matches--;

            // All frequencies match
            if (matches == 26)
                return true;
        }

        return false;
    }
};
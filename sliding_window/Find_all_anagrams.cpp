
/*
    Problem: Find All Anagrams in a String
    LeetCode: 438

    Approach:
    - Use a sliding window of size p.length().
    - Maintain frequency counts for:
        1. Pattern string (pCount)
        2. Current window (windowCount)
    - Keep a variable 'matches' representing how many of the
      26 character frequencies are currently equal.
    - When matches == 26, the current window is an anagram.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;

        int plen = p.length();
        int slen = s.length();

        if (slen < plen)
            return result;

        vector<int> windowCount(26, 0);
        vector<int> pCount(26, 0);

        // Build frequency arrays for first window and pattern
        for (int i = 0; i < plen; i++) {
            windowCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }

        // Count initial matches
        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (windowCount[i] == pCount[i])
                matches++;
        }

        // Check first window
        if (matches == 26)
            result.push_back(0);

        // Slide the window
        for (int i = plen; i < slen; i++) {

            int inChar = s[i] - 'a';
            int outChar = s[i - plen] - 'a';

            // Add incoming character
            windowCount[inChar]++;

            if (windowCount[inChar] == pCount[inChar])
                matches++;
            else if (windowCount[inChar] == pCount[inChar] + 1)
                matches--;

            // Remove outgoing character
            windowCount[outChar]--;

            if (windowCount[outChar] == pCount[outChar])
                matches++;
            else if (windowCount[outChar] == pCount[outChar] - 1)
                matches--;

            // All frequencies match
            if (matches == 26)
                result.push_back(i - plen + 1);
        }

        return result;
    }
};
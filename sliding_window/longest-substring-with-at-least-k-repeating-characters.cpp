#include<bits/stdc++.h>
using namespace std;

// ======================================================
// Problem Title: Longest Substring with At Least K Repeating Characters
// ======================================================

// Problem Description:
// Given a string s and an integer k, return the length of the longest substring
// such that every character in the substring appears at least k times.
//
// Approach:
// Use Divide and Conquer.
// For the current substring, count the frequency of each character.
// If every character appears at least k times, the entire substring is valid.
// Otherwise, any character whose frequency is less than k cannot be part of
// the answer. Treat such characters as separators, split the substring around
// them, recursively solve the left and right parts, and return the maximum
// length obtained.

class Solution {
public:
    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size(), k);
    }

    int solve(string& s, int start, int end, int k)
    {
        if (end - start < k) return 0;

        vector<int> freq(26, 0);

        for (int i = start; i < end; i++)
        {
            freq[s[i] - 'a']++;
        }

        for (int mid = start; mid < end; mid++)
        {
            if (freq[s[mid] - 'a'] >= k) continue;

            int next = mid + 1;

            while (next < end && freq[s[next] - 'a'] < k)
            {
                next++;
            }

            return max(solve(s, start, mid, k), solve(s, next, end, k));
        }

        return end - start;
    }
};

// ======================================================
// Time Complexity  : O(n²) in the worst case
// Space Complexity : O(26) for the frequency array in each
//                    recursive call (excluding recursion stack)
// ======================================================
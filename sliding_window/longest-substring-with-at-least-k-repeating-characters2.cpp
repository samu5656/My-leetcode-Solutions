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
// Use a sliding window by fixing the number of distinct characters in the
// window. Iterate the target number of distinct characters from 1 to 26.
// Maintain the frequency of characters, the number of unique characters, and
// the number of characters whose frequency is at least k.
// A window is valid when:
//     unique == targetDistinct && unique == countAtLeastK
// Update the maximum valid window length for every target distinct count.

class Solution {
public:
    int longestSubstring(string s, int k) {

        int ans = 0;

        for (int target = 1; target <= 26; target++)
        {
            vector<int> freq(26, 0);

            int unique = 0, countk = 0, left = 0, right = 0;

            while (right < s.size())
            {
                if (freq[s[right] - 'a'] == 0)
                    unique++;

                freq[s[right] - 'a']++;

                if (freq[s[right] - 'a'] == k)
                    countk++;

                while (unique > target)
                {
                    if (freq[s[left] - 'a'] == k)
                        countk--;

                    freq[s[left] - 'a']--;

                    if (freq[s[left] - 'a'] == 0)
                        unique--;

                    left++;
                }

                if (unique == target && unique == countk)
                {
                    ans = max(ans, right - left + 1);
                }

                right++;
            }
        }

        return ans;
    }
};

// ======================================================
// Time Complexity  : O(26 × n) ≈ O(n)
// Space Complexity : O(26) ≈ O(1)
// ======================================================
/*
    Problem: Maximum Number of Vowels in a Substring of Given Length
    Approach: Sliding Window

    Time Complexity: O(n)
    Space Complexity: O(1)

    Algorithm:
    1. Count the number of vowels in the first window of size k.
    2. Store this count as the initial maximum.
    3. Slide the window one character at a time:
       - Add the new incoming character if it is a vowel.
       - Remove the outgoing character if it is a vowel.
       - Update the maximum vowel count.
    4. Return the maximum count found.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int maxCount = 0;
        int count = 0;

        // Count vowels in the first window
        for (int i = 0; i < k; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u') {
                count++;
            }
        }

        // Store the vowel count of the first window
        maxCount = max(maxCount, count);

        // Slide the window across the string
        for (int i = k; i < s.length(); i++) {
            char in = s[i];      // Incoming character
            char out = s[i - k]; // Outgoing character

            // Add incoming vowel
            if (in == 'a' || in == 'e' || in == 'i' || in == 'o' || in == 'u')
                count++;

            // Remove outgoing vowel
            if (out == 'a' || out == 'e' || out == 'i' || out == 'o' ||
                out == 'u')
                count--;

            // Update maximum vowel count
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
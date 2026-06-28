#include<bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Longest Repeating Character Replacement
===========================================================

Description:
Given a string consisting of uppercase English letters and an integer k,
you can replace at most k characters in the string.

Return the length of the longest substring that can be obtained where all
characters are the same after performing at most k replacements.

Approach:
- Use the Sliding Window technique.
- Maintain the frequency of characters inside the current window.
- Keep track of the maximum frequency of any character in the window.
- If the number of characters to replace exceeds k, shrink the window
  from the left.
- Continuously update the maximum valid window length.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26]={};
        int maxfreq=0,maxlen=0,left=0;
        for(int right=0;right<s.length();right++)
        {
            freq[s[right]-'A']++;
            maxfreq = max(maxfreq,freq[s[right]-'A']);

            if((right-left+1)-maxfreq>k){
                freq[s[left]-'A']--;
                left++;
            }

            maxlen = max(maxlen,right-left+1);
        }

        return maxlen;
    }
};
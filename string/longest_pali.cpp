// LeetCode: Longest Palindrome
// Approach: Use a set to track unpaired characters. When a character repeats, form a pair (+2).
// At the end, if any character is left unpaired, place one in the center (+1).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> st;
        int len = 0;

        for (char c : s) {
            if (st.count(c)) {
                st.erase(c);
                len += 2;
            } else {
                st.insert(c);
            }
        }

        return st.empty() ? len : len + 1;
    }
};
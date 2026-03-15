/*
Problem: Is Subsequence
LeetCode Link: https://leetcode.com/problems/is-subsequence/

Approach:
1. Use two pointers:
   - i for string s
   - j for string t
2. Traverse both strings:
   - If characters match → move pointer i.
   - Always move pointer j.
3. If i reaches the length of s, all characters of s appeared in order in t.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.length() && j < t.length()) {
            if (s[i] == t[j])
                i++;
            j++;
        }

        return i == s.length();
    }
};
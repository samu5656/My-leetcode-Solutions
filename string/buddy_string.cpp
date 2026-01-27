/*
LeetCode 859 — Buddy Strings
https://leetcode.com/problems/buddy-strings/

Approach:
1) If lengths differ → false.
2) If s == goal → check whether any character appears more than once.
3) Otherwise, collect indices where characters differ.
   If exactly two indices i and j exist, verify:
   s[i] == goal[j] && s[j] == goal[i].
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        if (s == goal) {
            unordered_map<char, int> freq;
            for (int i = 0; i < s.size(); i++) {
                freq[s[i]]++;
                if (freq[s[i]] > 1) {
                    return true;
                }
            }
            return false;
        } else {
            vector<int> diff;
            for (int k = 0; k < s.size(); k++) {
                if (s[k] != goal[k]) {
                    diff.push_back(k);
                }
            }
            if (diff.size() != 2) {
                return false;
            }
            int i = diff[0];
            int j = diff[1];
            return (s[i] == goal[j] && s[j] == goal[i]);
        }
    }
};

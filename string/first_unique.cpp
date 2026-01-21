#include <bits/stdc++.h>
using namespace std;

/*
 * LeetCode 387: First Unique Character in a String
 * Difficulty: Easy
 *
 * Given a string s, find the first non-repeating character and return its index.
 * If it does not exist, return -1.
 */

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(256, 0);

        for (char c : s) {
            freq[c]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i]] == 1) {
                return i; 
            }
        }
        return -1;
    }
};


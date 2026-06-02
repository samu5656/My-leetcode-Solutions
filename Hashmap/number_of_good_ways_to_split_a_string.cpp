// LeetCode 1525: Number of Good Ways to Split a String
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSplits(string s) {
        int rightindex[26] = {};
        int distinctright = 0;
        int n = s.size();

        for (char ch : s) {
            if (rightindex[ch - 'a'] == 0) distinctright++;
            rightindex[ch - 'a']++;
        }

        bool leftindex[26] = {};
        int leftdistinct = 0;
        int count = 0;

        for (int i = 0; i < n - 1; i++) {
            int idx = s[i] - 'a';

            if (!leftindex[idx]) {
                leftindex[idx] = true;
                leftdistinct++;
            }

            rightindex[idx]--;

            if (rightindex[idx] == 0) distinctright--;

            if (leftdistinct == distinctright) count++;
        }

        return count;
    }
};
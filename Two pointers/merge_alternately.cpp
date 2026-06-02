// LeetCode 1768: Merge Strings Alternately

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int n = word1.size();
        int m = word2.size();

        for (int i = 0; i < max(n, m); i++) {
            if (i < n) result += word1[i];
            if (i < m) result += word2[i];
        }

        return result;
    }
};
// LeetCode 1768: Merge Strings Alternately

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int j = 0;
        int i = 0;
        string result = "";

        while (i < word1.size() && j < word2.size()) {
            result += word1[i];
            result += word2[j];
            i++;
            j++;
        }

        if (i == word1.size())
            result += word2.substr(j);

        if (j == word2.size())
            result += word1.substr(i);

        return result;
    }
};
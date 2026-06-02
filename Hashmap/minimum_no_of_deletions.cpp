// LeetCode 1647: Minimum Deletions to Make Character Frequencies Unique

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int deletions = 0;

        for (int i = 1; i < 26; i++) {
            if (freq[i] >= freq[i - 1]) {
                int allowed = max(0, freq[i - 1] - 1);
                deletions += freq[i] - allowed;
                freq[i] = allowed;
            }
        }

        return deletions;
    }
};
#include <bits/stdc++.h>
using namespace std;

// LeetCode 792: Number of Matching Subsequences
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> charpositions(26);

        for (int i = 0; i < s.length(); i++) {
            charpositions[s[i] - 'a'].push_back(i);
        }

        int count = 0;

        for (const string& word : words) {
            if (isSubsequence(word, charpositions)) {
                count++;
            }
        }

        return count;
    }

private:
    bool isSubsequence(const string& word, const vector<vector<int>>& charpositions) {
        int previous = -1;

        for (char c : word) {
            const vector<int>& positions = charpositions[c - 'a'];

            auto it = upper_bound(positions.begin(), positions.end(), previous);

            if (it == positions.end()) {
                return false;
            }

            previous = *it;
        }

        return true;
    }
};
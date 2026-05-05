// LeetCode 843: Guess the Word
// https://leetcode.com/problems/guess-the-word/

#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
 class Master {
    public:
      int guess(string word);
 };


class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        vector<string> candidates(words.begin(), words.end());

        while (!candidates.empty()) {
            string bestGuess = getBestGuess(candidates);

            int matches = master.guess(bestGuess);
            if (matches == 6) return;

            vector<string> filtered;
            for (string& word : candidates) {
                if (match(word, bestGuess) == matches) {
                    filtered.push_back(word);
                }
            }

            candidates = filtered;
        }
    }

private:
    string getBestGuess(vector<string>& candidates) {
        string bestGuess = candidates[0];
        int bestCount = INT_MAX;

        for (string& guess : candidates) {
            vector<int> groups(7, 0);

            for (string& word : candidates) {
                int matches = match(word, guess);
                groups[matches]++;
            }

            int worst = 0;
            for (int count : groups) {
                worst = max(worst, count);
            }

            if (worst < bestCount) {
                bestCount = worst;
                bestGuess = guess;
            }
        }

        return bestGuess;
    }

    int match(string& a, string& b) {
        int count = 0;

        for (int i = 0; i < 6; i++) {
            if (a[i] == b[i]) count++;
        }

        return count;
    }
};
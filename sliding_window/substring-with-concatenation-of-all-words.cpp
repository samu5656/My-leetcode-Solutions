#include<bits/stdc++.h>
using namespace std;

/*
=========================================================
Problem Title:
Substring with Concatenation of All Words

Problem Description:
You are given a string s and an array of strings words. All the strings in
words are of the same length.

A concatenated substring is a string that contains every word in words
exactly once, in any order, and without any intervening characters.

Return all the starting indices of the concatenated substrings in s.
You can return the answer in any order.

Time Complexity:
O(N * W)
where N = length of s and W = length of each word.

Space Complexity:
O(K)
where K = number of unique words in words.
=========================================================
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty())
            return result;

        int w = words[0].length();
        int c = words.size();
        int window = w * c;

        if (s.length() < window)
            return result;

        unordered_map<string, int> target;

        for (int i = 0; i < words.size(); i++) {
            target[words[i]]++;
        }

        for (int offset = 0; offset < w; offset++) {
            int left = offset;

            unordered_map<string, int> seen;
            int count = 0;

            for (int right = offset; right + w <= s.length(); right += w) {
                string word = s.substr(right, w);

                if (target.count(word)) {
                    seen[word]++;
                    count++;

                    while (seen[word] > target[word]) {
                        string leftword = s.substr(left, w);
                        seen[leftword]--;
                        left += w;
                        count--;
                    }

                    if (count == c ) {
                        result.push_back(left);

                        string leftword = s.substr(left, w);
                        seen[leftword]--;
                        left += w;
                        count--;
                    }
                } else {
                    seen.clear();
                    count = 0;
                    left = right + w;
                }
            }
        }
        return result;
    }
};
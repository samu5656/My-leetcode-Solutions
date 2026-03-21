/*
Title: Word Pattern
Link: https://leetcode.com/problems/word-pattern/
Approach:
Split the string into words and ensure a bijection between pattern characters and words.
Use two hash maps: char → word and word → char.
Validate consistency while iterating through pattern and words.
Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp = "";
        for (char c : s) {
            if (c == ' ') {
                words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        words.push_back(temp);
        if (pattern.length() != words.size()) return false;
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        for (int i = 0; i < pattern.length(); i++) {
            char a = pattern[i];
            string b = words[i];
            if (map1.count(a)) {
                if (map1[a] != b) return false;
            } else {
                map1[a] = b;
            }
            if (map2.count(b)) {
                if (map2[b] != a) return false;
            } else {
                map2[b] = a;
            }
        }
        return true;
    }
};
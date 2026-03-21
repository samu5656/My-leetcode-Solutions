/*
Title: Isomorphic Strings
Link: https://leetcode.com/problems/isomorphic-strings/
Approach:
Use two hash maps to maintain a bijection between characters of both strings.
One map stores s → t mapping and the other stores t → s mapping.
Traverse both strings simultaneously and ensure consistency in both mappings.
Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> mapS;
        unordered_map<char, char> mapT;
        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];
            if (mapS.count(a)) {
                if (mapS[a] != b) return false;
            } else {
                mapS[a] = b;
            }
            if (mapT.count(b)) {
                if (mapT[b] != a) return false;
            } else {
                mapT[b] = a;
            }
        }
        return true;
    }
};
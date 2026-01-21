#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            while (chars.count(s[right])) {
                chars.erase(s[left]);
                left++;
            }
            chars.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

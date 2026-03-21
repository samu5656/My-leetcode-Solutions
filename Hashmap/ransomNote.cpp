/*
Problem: Ransom Note
Link: https://leetcode.com/problems/ransom-note/

Approach:
- Count frequency of each character in magazine using a hashmap.
- Traverse ransomNote and check if each character is available.
- Decrease frequency as characters are used.
- If any character is unavailable (freq == 0), return false.

Time Complexity: O(n + m)
Space Complexity: O(1) (bounded by character set)
*/
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if (magazine.empty()) return false;

        unordered_map<char, int> freq;

        for (int i = 0; i < magazine.length(); i++) {
            freq[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            char s = ransomNote[i];
            if (freq[s] == 0) return false;
            freq[s]--;
        }

        return true;
    }
};
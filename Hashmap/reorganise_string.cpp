/*
    LeetCode 767 - Reorganize String
    Link: https://leetcode.com/problems/reorganize-string/

    Approach:
    - Count the frequency of each character.
    - Find the character with maximum frequency.
    - If its frequency is greater than (n + 1) / 2,
      it is impossible to rearrange the string without
      adjacent equal characters, so return "".
    - Place the most frequent character at even indices
      (0, 2, 4, ...).
    - Fill the remaining characters in the remaining
      even positions and then odd positions.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {};

        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxFreq = 0, maxChar = 0;

        for (int i = 0; i < 26; i++) {
            if (maxFreq < freq[i]) {
                maxFreq = freq[i];
                maxChar = i;
            }
        }

        int n = s.length();

        if (maxFreq > (n + 1) / 2)
            return "";

        string result(n, ' ');
        int idx = 0;

        // Place the most frequent character first
        while (freq[maxChar] > 0) {
            result[idx] = (char)(maxChar + 'a');
            freq[maxChar]--;
            idx += 2;
        }

        // Fill remaining characters
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (idx >= n)
                    idx = 1;

                result[idx] = (char)(i + 'a');
                freq[i]--;
                idx += 2;
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    string s = "aab";

    string ans = obj.reorganizeString(s);

    cout << "Input String  : " << s << endl;
    cout << "Output String : " << ans << endl;

    return 0;
}

/*
Dry Run:

Input:
s = "aab"

Frequency:
a -> 2
b -> 1

maxFreq = 2
maxChar = 'a'

n = 3

Check:
2 > (3 + 1)/2 ?
2 > 2 ? No

result = [ , , ]
idx = 0

Place 'a':
result = [a, , ]
idx = 2

Place 'a':
result = [a, , a]
idx = 4

idx >= n, so idx = 1

Place 'b':
result = [a, b, a]

Output:
"aba"
*/
// LeetCode 68: Text Justification
// https://leetcode.com/problems/text-justification/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int n = words.size();

        while (i < n) {
            int j = i;
            int line_length = 0;

            while (j < n && line_length + words[j].length() + (j - i) <= maxWidth) {
                line_length += words[j].length();
                j++;
            }

            int gaps = j - i - 1;
            string line = "";

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += " ";
                }
                line += string(maxWidth - line.length(), ' ');
            } 
            else {
                int space = maxWidth - line_length;
                int each = space / gaps;
                int extra = space % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        int spaces = each + (extra > 0 ? 1 : 0);
                        line += string(spaces, ' ');
                        if (extra > 0) extra--;
                    }
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
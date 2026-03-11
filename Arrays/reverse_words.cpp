// Reverse Words in a String
// LeetCode: https://leetcode.com/problems/reverse-words-in-a-string/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        s.erase(0, s.find_first_not_of("\t\n\f\v"));
        s.erase(s.find_last_not_of("\t\n\v\f") + 1);

        vector<string> m;
        string res;
        string word = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                word += s[i];
            } else {
                if (!word.empty()) {
                    m.push_back(word);
                    word = "";
                }
            }
        }

        if (!word.empty()) {
            m.push_back(word);
        }

        for (int i = m.size() - 1; i >= 0; i--) {
            res += m[i];
            if (i != 0) {
                res += " ";
            }
        }

        return res;
    }
};
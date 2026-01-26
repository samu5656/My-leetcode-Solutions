// LeetCode Problem 844 — Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '#') {
                if (!a.empty()) {
                    a.pop_back();
                }
            } else {
                a.push_back(s[i]);
            }
        }

        for (int i = 0; i < t.size(); i++) {
            if (t[i] == '#') {
                if (!b.empty()) {
                    b.pop_back();
                }
            } else {
                b.push_back(t[i]);
            }
        }

        return a == b;
    }
};

int main() {
    Solution obj;

    string s, t;
    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    cout << (obj.backspaceCompare(s, t) ? "True" : "False");

    return 0;
}

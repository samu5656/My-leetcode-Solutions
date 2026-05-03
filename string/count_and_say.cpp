// LeetCode: Count and Say
// Approach: Start with "1". For each iteration, group consecutive same digits
// using two pointers (i, j), count them, and build the next string as count + digit.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";

        for (int k = 2; k <= n; k++) {
            string temp = "";
            int i = 0;

            while (i < res.length()) {
                int j = i;

                while (j < res.length() && res[i] == res[j]) {
                    j++;
                }

                int count = j - i;
                temp += to_string(count);
                temp += res[i];

                i = j;
            }

            res = temp;
        }

        return res;
    }
};
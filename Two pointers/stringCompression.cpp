// LeetCode 443. String Compression

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        int start = 0;

        while (read < chars.size()) {
            start = read;

            while (read < chars.size() && chars[start] == chars[read]) {
                read++;
            }

            int count = read - start;

            chars[write] = chars[start];
            write++;

            if (count > 1) {
                string count_char = to_string(count);

                for (char c : count_char) {
                    chars[write] = c;
                    write++;
                }
            }
        }

        return write;
    }
};
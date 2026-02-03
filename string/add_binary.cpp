#include <bits/stdc++.h>
using namespace std;

// LeetCode 67 — Add Binary: Given two binary strings, return their sum as a binary string.
class Solution {
public:
    string addBinary(string a, string b) {
        int s = a.size() - 1;
        int t = b.size() - 1;
        int carry = 0;
        string res = "";

        while (s >= 0 || t >= 0 || carry) {
            int x = (s >= 0) ? a[s--] - '0' : 0;
            int y = (t >= 0) ? b[t--] - '0' : 0;

            int sum = x ^ y ^ carry;
            carry = (x & y) | (carry & (x ^ y));

            res.push_back(sum + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
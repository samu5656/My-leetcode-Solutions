// LeetCode 696 - Count Binary Substrings
// Time Complexity: O(n)
// Space Complexity: O(n)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 1;
        vector<int> count_bit;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1])
                count++;
            else {
                count_bit.push_back(count);
                count = 1;
            }
        }

        count_bit.push_back(count);

        int result = 0;

        for (int i = 1; i < count_bit.size(); i++) {
            result += min(count_bit[i], count_bit[i - 1]);
        }

        return result;
    }
};
// LeetCode 128 - Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());

        int maxcount = 0;

        for (int nums : numset) {
            // Start counting only if this number is the beginning
            // of a consecutive sequence
            if (numset.find(nums - 1) == numset.end()) {

                int curr_no = nums;
                int count = 1;

                // Count consecutive numbers
                while (numset.find(curr_no + 1) != numset.end()) {
                    count++;
                    curr_no++;
                }

                maxcount = max(maxcount, count);
            }
        }

        return maxcount;
    }
};
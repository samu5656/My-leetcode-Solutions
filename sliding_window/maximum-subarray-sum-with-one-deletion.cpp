/*
===========================================================
LeetCode 1186. Maximum Subarray Sum with One Deletion
===========================================================

Problem:
Given an integer array, return the maximum subarray sum with at most
one element deleted.

Approach:
- Maintain two DP states:
  1. prevnotdel : Maximum subarray sum ending at the current index
                  without any deletion.
  2. prevwithdel: Maximum subarray sum ending at the current index
                  after one deletion.

Transitions:
- prevnotdel = max(prevnotdel + arr[i], arr[i])
- prevwithdel = max(previous_prevnotdel, prevwithdel + arr[i])

Time Complexity : O(n)
Space Complexity: O(1)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int prevwithdel = INT_MIN, prevnotdel = arr[0];
        int maxi = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int temp = prevnotdel;

            prevnotdel = max(prevnotdel + arr[i], arr[i]);
            prevwithdel = max(temp, prevwithdel + arr[i]);

            int current = max(prevnotdel, prevwithdel);
            maxi = max(current, maxi);
        }

        return maxi;
    }
};
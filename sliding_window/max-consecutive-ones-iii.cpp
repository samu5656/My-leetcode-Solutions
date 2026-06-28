#include<bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Max Consecutive Ones III
===========================================================

Description:
Given a binary array nums and an integer k, return the maximum number
of consecutive 1's in the array if you can flip at most k 0's.

Approach:
- Use the Sliding Window technique.
- Expand the window by moving the right pointer.
- Count the number of 0's inside the current window.
- If the number of 0's exceeds k, shrink the window from the left
  until it becomes valid again.
- Track the maximum valid window length throughout the traversal.

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxlen = 0, freq = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0)
                freq++;

            while (freq > k) {
                if (nums[left] == 0) {
                    freq--;
                }
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};
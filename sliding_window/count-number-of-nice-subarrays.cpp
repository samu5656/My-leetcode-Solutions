#include<bits/stdc++.h>
using namespace std;

/*
===========================================================
Problem: Count Number of Nice Subarrays
===========================================================

Description:
Given an integer array nums and an integer k, return the number of
continuous subarrays that contain exactly k odd numbers.

Approach:
- Use the Sliding Window technique with the "At Most K" trick.
- Create a helper function that counts the number of subarrays
  containing at most k odd numbers.
- For each valid window, all subarrays ending at the current index
  and starting anywhere within the window are valid, so add
  (right - left + 1) to the count.
- The number of subarrays containing exactly k odd numbers is:
      AtMost(k) - AtMost(k - 1)

Time Complexity: O(n)
Space Complexity: O(1)
===========================================================
*/

class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int left = 0, count = 0, odd = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 != 0)
                odd++;

            while (odd > k) {
                if (nums[left] % 2 != 0) {
                    odd--;
                }
                left++;
            }

            count += right - left + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};
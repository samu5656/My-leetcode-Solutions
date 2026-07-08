#include<bits/stdc++.h>
using namespace std;

// Problem: 992. Subarrays with K Different Integers
// Description:
// Given an integer array nums and an integer k, return the number of good subarrays of nums.
// A good subarray contains exactly k distinct integers.
//
// Time Complexity: O(n)
// Space Complexity: O(k) average, O(n) worst case

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums, k) - subarray(nums, k - 1);
    }

    int subarray(vector<int>& nums, int k) {
        int l = 0, i = 0, count = 0;
        unordered_map<int, int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;

            while (freq.size() > k) {
                freq[nums[l]]--;

                if (freq[nums[l]] == 0) {
                    freq.erase(nums[l]);
                }

                l++;
            }

            count += i - l + 1;
        }

        return count;
    }
};
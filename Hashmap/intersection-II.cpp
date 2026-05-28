/*
LeetCode 350. Intersection of Two Arrays II
Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

Approach:
Use a hashmap to store frequencies of elements
from the smaller array.

Traverse the second array:
- If element frequency is greater than 0,
  add it to the result.
- Decrease frequency after using it.

This efficiently handles duplicates.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        // Always build hashmap from smaller array
        // to optimize space complexity
        if(nums1.size() > nums2.size())
        {
            return intersect(nums2, nums1);
        }

        unordered_map<int,int> freq;

        // Store frequencies of nums1
        for(int num : nums1)
        {
            freq[num]++;
        }

        vector<int> result;

        // Find common elements
        for(int num : nums2)
        {
            if(freq[num] > 0)
            {
                result.push_back(num);
                freq[num]--;
            }
        }

        return result;
    }
};
/*
=========================================================
LeetCode Problem: 80
Title: Remove Duplicates from Sorted Array II
Difficulty: Medium

Given a sorted array nums, remove the duplicates in-place
such that each unique element appears at most twice.
Return the new length k. The first k elements should contain
the final result.

Constraints:
- 0 <= nums.length <= 3 * 10^4
- -10^4 <= nums[i] <= 10^4
- nums is sorted in non-decreasing order

Approach:
Two-pointer overwrite technique.
- First two elements are always allowed.
- For each next element, compare with nums[k-2].
- If different → keep it and advance k.

Time Complexity: O(n)
Space Complexity: O(1)
=========================================================
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        int k = 2; 

        for (int i = 2; i < n; i++) {
            if (nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
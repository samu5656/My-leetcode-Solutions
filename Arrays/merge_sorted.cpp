/******************************************************
 * Problem: Merge Two Sorted Arrays
 * Platform: LeetCode 88
 * Description:
 *   You are given two sorted integer arrays nums1 and
 *   nums2, and two integers m and n representing the
 *   number of valid elements in nums1 and nums2.
 *
 *   Merge nums2 into nums1 as one sorted array.
 *
 * Constraints:
 *   - nums1 has size (m + n)
 *   - First m elements of nums1 are valid
 *   - nums2 contains n elements
 *
 * Approach:
 *   Reverse Two-Pointer / In-Place Merge
 *
 * Idea:
 *   Start comparing elements from the end of both
 *   arrays so that existing elements in nums1 are not
 *   overwritten.
 *
 * Time Complexity:  O(m + n)
 * Space Complexity: O(1)
 ******************************************************/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        
        int i = m - 1;        
        int j = n - 1;       
        int k = m + n - 1;    

       
        while (j >= 0) {

            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
    }
};
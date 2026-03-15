/*
Problem: Two Sum II – Input Array Is Sorted
LeetCode Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Approach:
1. Use the two-pointer technique since the array is sorted.
2. Start with i = 0 (left pointer) and j = n-1 (right pointer).
3. Compute sum = numbers[i] + numbers[j].
   - If sum == target → return indices (1-based).
   - If sum < target → move left pointer (i++) to increase sum.
   - If sum > target → move right pointer (j--) to decrease sum.

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        while (i < j) {
            int sum = numbers[i] + numbers[j];

            if (sum == target)
                return {i + 1, j + 1};
            else if (sum < target)
                i++;
            else
                j--;
        }

        return {};
    }
};
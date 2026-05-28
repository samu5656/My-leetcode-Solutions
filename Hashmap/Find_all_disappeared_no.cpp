/*
LeetCode 448 - Find All Numbers Disappeared in an Array
Link: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

Approach:
- Each number in the array is in the range [1, n].
- Use the value of each element as an index.
- Mark the corresponding index as negative to indicate that the number exists.
- After marking, the indices having positive values represent missing numbers.

Time Complexity: O(n)
Space Complexity: O(1) (excluding result array)
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;

        // Mark visited numbers
        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        // Find missing numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};
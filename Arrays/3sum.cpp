/*
Problem: 3Sum
LeetCode Link: https://leetcode.com/problems/3sum/

Approach:
1. Sort the array.
2. Fix one element nums[i] and use two pointers (l = i+1, r = n-1).
3. If sum = nums[i] + nums[l] + nums[r]:
   - sum == 0 → store triplet, move both pointers and skip duplicates.
   - sum < 0  → move left pointer.
   - sum > 0  → move right pointer.
4. Skip duplicate values of nums[i] to avoid repeated triplets.

Time Complexity: O(n^2)
Space Complexity: O(1) (excluding output)
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1, r = n - 1;

            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if (sum < 0)
                    l++;
                else
                    r--;
            }
        }

        return res;
    }
};
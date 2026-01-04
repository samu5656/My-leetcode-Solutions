#include <bits/stdc++.h>
using namespace std;

/*
 Problem: Maximum Subarray
 LeetCode: https://leetcode.com/problems/maximum-subarray/
 Difficulty: Easy
 Algorithm: Kadane's Algorithm
 Time Complexity: O(n)
 Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int max_sum = nums[0];
        int curr_sum = nums[0];

        for (int i = 1; i < n; i++) {
            curr_sum = max(nums[i], curr_sum + nums[i]);
            max_sum = max(max_sum, curr_sum);
        }

        return max_sum;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}

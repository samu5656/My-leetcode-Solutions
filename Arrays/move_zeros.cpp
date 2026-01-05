/*
    Problem: Move Zeroes
    LeetCode: https://leetcode.com/problems/move-zeroes/
    Difficulty: Easy
    Topic: Array, Two Pointers
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;

        // Move all non-zero elements to the front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[pos++] = nums[i];
            }
        }

        // Fill the remaining positions with zeroes
        while (pos < nums.size()) {
            nums[pos++] = 0;
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    Solution sol;
    sol.moveZeroes(nums);

    cout << "Result: ";
    for (int x : nums) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}

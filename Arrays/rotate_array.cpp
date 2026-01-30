#include <vector>
#include <algorithm>
using namespace std;

// LeetCode 189 — Rotate Array (https://leetcode.com/problems/rotate-array/) | Approach: Reversal algorithm (reverse whole array, then first k, then remaining)

class Solution {
public:
    void reverseRange(vector<int>& nums, int left, int right) {
        while (left < right) {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k %= n;

        reverseRange(nums, 0, n - 1);
        reverseRange(nums, 0, k - 1);
        reverseRange(nums, k, n - 1);
    }
};
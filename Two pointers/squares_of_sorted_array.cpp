// LeetCode 977: Squares of a Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int pos = nums.size() - 1;

        vector<int> result(nums.size());

        while (left <= right) {
            int leftsqr = nums[left] * nums[left];
            int rightsqr = nums[right] * nums[right];

            if (leftsqr > rightsqr) {
                result[pos--] = leftsqr;
                left++;
            } else {
                result[pos--] = rightsqr;
                right--;
            }
        }

        return result;
    }
};
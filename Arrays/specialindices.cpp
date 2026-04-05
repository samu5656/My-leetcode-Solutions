#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long solve(vector<int>& nums, int start) {
        long long ops = 0;

        for (int i = start; i < nums.size() - 1; i += 2) {
            int target = max(nums[i - 1], nums[i + 1]) + 1;

            if (nums[i] < target) {
                ops += (target - nums[i]);
            }
        }
        return ops;
    }

    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        long long ops1 = solve(nums, 1);
        long long ops2 = solve(nums, 2);

        return min(ops1, ops2);
    }
};
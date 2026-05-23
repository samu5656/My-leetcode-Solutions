/*
LeetCode 645 - Set Mismatch
Link: https://leetcode.com/problems/set-mismatch/

Approach:
Use XOR to cancel all equal numbers between nums and 1 to n.
The remaining XOR gives duplicate ^ missing.
Use the rightmost set bit to separate them into two buckets,
then identify which value is duplicate by checking nums.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int xr = 0;

        for (int i = 0; i < n; i++) {
            xr ^= nums[i];
            xr ^= (i + 1);
        }

        int setbit = xr & (-xr);

        int bucket1 = 0;
        int bucket2 = 0;

        for (int num : nums) {
            if (num & setbit)
                bucket1 ^= num;
            else
                bucket2 ^= num;
        }

        for (int i = 1; i <= n; i++) {
            if (i & setbit)
                bucket1 ^= i;
            else
                bucket2 ^= i;
        }

        for (int num : nums) {
            if (num == bucket1)
                return {bucket1, bucket2};
        }

        return {bucket2, bucket1};
    }
};
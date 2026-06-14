/*
LeetCode 560. Subarray Sum Equals K

Problem Link:
https://leetcode.com/problems/subarray-sum-equals-k/
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefix_sum = 0;
        unordered_map<int, int> prefix_count;

        prefix_count[0] = 1;

        for (int num : nums) {
            prefix_sum += num;

            if (prefix_count.count(prefix_sum - k)) {
                count += prefix_count[prefix_sum - k];
            }

            prefix_count[prefix_sum]++;
        }

        return count;
    }
};
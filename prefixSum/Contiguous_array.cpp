#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
    Problem: Contiguous Array
    Link: https://leetcode.com/problems/contiguous-array/

    Approach:
    - Convert 0 to -1.
    - Use prefix sum and store the first occurrence of each prefix sum.
    - If the same prefix sum appears again, the subarray between them
      contains an equal number of 0s and 1s.
    - Track the maximum length.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_length = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                nums[i] = -1;
            }
        }

        unordered_map<int, int> prefix_index;
        prefix_index[0] = -1;

        int prefix_sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            prefix_sum += nums[i];

            if (prefix_index.count(prefix_sum)) {
                max_length = max(max_length, i - prefix_index[prefix_sum]);
            } else {
                prefix_index[prefix_sum] = i;
            }
        }

        return max_length;
    }
};
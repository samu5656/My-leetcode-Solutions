#include <vector>
#include <algorithm>
using namespace std;

/*
===========================================================
LeetCode 1014. Best Sightseeing Pair
===========================================================

Problem:
Given an integer array values, where values[i] represents the value
of the i-th sightseeing spot, return the maximum score of a pair
(i, j) such that i < j.

Score = values[i] + values[j] + i - j

Approach:
- Rewrite the score as:
      (values[i] + i) + (values[j] - j)
- While traversing the array, maintain the maximum value of
  (values[i] + i) seen so far.
- For each index j, compute (values[j] - j) and combine it with
  the best previous (values[i] + i).
- Update the maximum score and then update the best
  (values[i] + i) for future indices.

Time Complexity : O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int first = values[0];
        int second = 0;
        int maxsum = 0;

        for (int j = 1; j < values.size(); j++) {
            second = values[j] - j;
            maxsum = max(maxsum, first + second);
            first = max(first, values[j] + j);
        }

        return maxsum;
    }
};
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
===========================================================
LeetCode 978. Longest Turbulent Subarray
===========================================================

Problem:
Given an integer array arr, return the length of the longest
turbulent subarray.

A subarray is turbulent if the comparison signs between adjacent
elements alternate continuously (>, <, >, < ... or <, >, <, > ...).

Approach:
- Use the Sliding Window technique.
- Maintain a window [l, r] and track the previous comparison
  using a string ("<" or ">").
- If the current comparison alternates with the previous one,
  expand the window and update the maximum length.
- Otherwise, reset the window appropriately. If adjacent elements
  are equal, move past them since turbulence cannot continue.

Time Complexity : O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int r = 1, l = 0, result = 1;
        string prev = "";

        while (r < arr.size()) {
            if (arr[r] < arr[r - 1] && prev != "<") {
                result = max(result, r - l + 1);
                r += 1;
                prev = "<";
            }
            else if (arr[r] > arr[r - 1] && prev != ">") {
                result = max(result, r - l + 1);
                r += 1;
                prev = ">";
            }
            else {
                if (arr[r] == arr[r - 1])
                    r += 1;

                l = r - 1;
                prev = "";
            }
        }

        return result;
    }
};
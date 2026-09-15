/*
    Problem: Daily Temperatures
    Difficulty: Medium
    Link: https://leetcode.com/problems/daily-temperatures/

    Algorithm:
    Monotonic Decreasing Stack

    Approach:
    Traverse the array from right to left.
    Store indices in a stack.

    For each temperature:
    1. Remove indices whose temperatures are <= current temperature.
       They cannot be the next warmer day.
    2. If the stack is not empty, the top gives the nearest warmer day.
    3. Store the difference between the indices.
    4. Push the current index into the stack.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> res(n, 0);
        stack<int> st;

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Remove temperatures that are not warmer
            // than the current temperature
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If a warmer day exists
            if (!st.empty()) {
                res[i] = st.top() - i;
            }

            // Store the current index
            st.push(i);
        }

        return res;
    }
};

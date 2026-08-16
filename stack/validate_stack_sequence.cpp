#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Problem: 946. Validate Stack Sequences
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/validate-stack-sequences/
 *
 * Algorithm:
 * Stack Simulation
 *
 * Approach:
 * - Use a stack to simulate the push and pop operations.
 * - Traverse every element in the pushed array and push it onto the stack.
 * - After each push, check whether the top of the stack matches the
 *   current element in the popped array.
 * - If they match, pop the element and move to the next element in popped.
 * - Continue this process until all elements in pushed are processed.
 * - If all elements in popped are successfully matched, the sequence is valid.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {

        // Stack used to simulate push and pop operations
        stack<int> st;

        // Pointer to the current element in popped
        int j = 0;

        // Process each element from pushed
        for (int x : pushed) {

            // Push the current element onto the stack
            st.push(x);

            // Pop while the top matches the required popped element
            while (!st.empty() && j < popped.size() &&
                   st.top() == popped[j]) {

                st.pop();
                j++;
            }
        }

        // All elements must have been successfully popped
        return j == popped.size();
    }
};
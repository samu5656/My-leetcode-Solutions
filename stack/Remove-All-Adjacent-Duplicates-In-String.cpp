/**
 * Problem: 1047. Remove All Adjacent Duplicates In String
 * Difficulty: Easy
 * Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 *
 * Algorithm:
 * Stack Simulation using String
 *
 * Approach:
 * - Use a string as a stack to simulate stack operations.
 * - Traverse each character of the input string.
 * - If the stack is not empty and the current character matches the
 *   top of the stack, remove the top character.
 * - Otherwise, push the current character onto the stack.
 * - After processing all characters, the stack contains the final
 *   string with all adjacent duplicates removed.
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    string removeDuplicates(string s) {

        // String used as a stack
        string stack;

        // Traverse each character of the input string
        for (char c : s) {

            // Remove adjacent duplicate if present
            if (!stack.empty() && stack.back() == c) {
                stack.pop_back();
            }
            else {

                // Push the current character
                stack.push_back(c);
            }
        }

        // Return the resulting string
        return stack;
    }
};